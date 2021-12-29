# IMPORTO TUTTI I MODULI CHE MI SERVIRANNO
import serial
import struct
import time
from cvzone.HandTrackingModule import HandDetector
import cv2

# INIZIALIZZO LA VIDEOCAMERA
cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=1, maxHands=2)
# INIZIALIZZO COMUNICAZIONE SERIALE
arduino = serial.Serial("COM3", 9600)

while True:
    # PRENDO IL SINGOLO FRAME DELL'IMMAGINE
    success, img = cap.read()
    # TROVO LA MANO E I PUNTI
    hands, img = detector.findHands(img)
    
    if hands:
        hand1 = hands[0]
        lmList1 = hand1["lmList"]  # LISTA DEI 21 PUNTI DELLA MANO
        bbox1 = hand1["bbox"]  # INFO DELLE DIMENSIONI DELLA MANO
        centerPoint1 = hand1['center']  # PRENDO IL CENTRO DELLA MANO
        handType1 = hand1["type"]  # CAPISCE SE MANO DESTRA O SINISTRA

        fingers1 = detector.fingersUp(hand1) # TROVO QUALE DITO È ALZATO
        print(fingers1)
        # INVIO I DATI AD ARDUINO
        arduino.write(struct.pack('>BBBBB',fingers1[0],fingers1[1],fingers1[2],fingers1[3],fingers1[4]))
        
    # Display
    cv2.imshow("Image", img)
    cv2.waitKey(1)
cap.release()
cv2.destroyAllWindows()