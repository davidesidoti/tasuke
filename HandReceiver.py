# IMPORTO TUTTI I MODULI CHE MI SERVIRANNO
import cv2
import serial
import struct
from cvzone.HandTrackingModule import HandDetector

# INIZIALIZZO LA VIDEOCAMERA
cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=1)
# INIZIALIZZO COMUNICAZIONE SERIALE
arduino = serial.Serial("COM3", 9600)

while True:
    # Get image frame
    success, img = cap.read()
    # Find the hand and its landmarks
    hands, img = detector.findHands(img)  # with draw
    # hands = detector.findHands(img, draw=False)  # without draw

    if hands:
        # Hand 1
        hand = hands[0]
        lmList = hand["lmList"]  # List of 21 Landmark points
        bbox = hand["bbox"]  # Bounding box info x,y,w,h
        centerPoint = hand['center']  # center of the hand cx,cy
        handType = hand["type"]  # Handtype Left or Right

        fingers = detector.fingersUp(hand)
        # ! QUESTE RIGHE SERVONO PER MUOVERE I SERVO IN BASE ALL'ANGOLAZIONE DELLE DITA
        # thumb_length, info1, img = detector.findDistance(lmList[4], lmList[2], img)  # with draw
        # index_length, info2, img = detector.findDistance(lmList[8], lmList[5], img)  # with draw
        # middle_length, info3, img = detector.findDistance(lmList[12], lmList[9], img)  # with draw
        # ring_length, info4, img = detector.findDistance(lmList[16], lmList[13], img)  # with draw
        # pinky_length, info5, img = detector.findDistance(lmList[20], lmList[17], img)  # with draw
        # arduino.write(struct.pack('>BBBBB', int(thumb_length), int(index_length), int(middle_length), int(ring_length), int(pinky_length)))
        arduino.write(struct.pack('>BBBBB', fingers[0], fingers[1], fingers[2], fingers[3], fingers[4]))

    # Display
    cv2.imshow("Image", img)
    cv2.waitKey(1)
cap.release()
cv2.destroyAllWindows()
