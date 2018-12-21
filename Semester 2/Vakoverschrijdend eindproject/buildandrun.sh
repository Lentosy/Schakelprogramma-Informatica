#!/usr/bin/env bash

echo -e "[INF] \t Building and starting containers (might take some time)"
docker-compose -f docker/annotatietool-01.yml up --build -d --no-color >& annotatietool-01-compose.log
echo -e "[INF] \t Docker-compose logs written to annotatietool-01-compose.log" 
echo -e "[INF] \t NodeJS running at http://localhost:9010"
echo -e "[INF] \t MongoDB can be accessed from the NodeJS container"
echo -e "      \t at mongodb://annotatietool-01-mongodb:27017"