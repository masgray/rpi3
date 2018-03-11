#/bin/bash

APP_NAME=test-arm
BIN_SRC_PATH=./build/bin
DST_IP=pi@192.168.0.5
BIN_DST_PATH=$DST_IP:/home/pi
SERVICE_DST_PATH=/etc/systemd/system
SERVICE_NAME=$APP_NAME.service

ssh $DST_IP "sudo systemctl stop $SERVICE_NAME"
ssh $DST_IP "sudo systemctl disable $SERVICE_NAME"
scp $BIN_SRC_PATH/$APP_NAME $BIN_DST_PATH/$APP_NAME
scp $BIN_SRC_PATH/$SERVICE_NAME $BIN_DST_PATH/$SERVICE_NAME
ssh $DST_IP "sudo cp -f /home/pi/$SERVICE_NAME $SERVICE_DST_PATH/$SERVICE_NAME"
ssh $DST_IP "sudo systemctl start $SERVICE_NAME"
ssh $DST_IP "sudo systemctl enable $SERVICE_NAME"
