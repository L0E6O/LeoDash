#!/bin/bash
IP=$(ip route get 1 | awk '{print $NF;exit}')
echo "REACT_APP_API_URL=$IP" > .env