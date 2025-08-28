#!/bin/bash
IP=$(ip route get 1 | awk '{print $7}')
echo "REACT_APP_API_URL=$IP" > .env