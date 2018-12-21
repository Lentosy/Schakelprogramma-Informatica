# Base image for x64/x86
FROM node:boron					

# Create app directory
RUN mkdir -p /usr/src/app
ADD project /usr/src/app/
WORKDIR /usr/src/app

# Install dependencies
#COPY project/package.json  /usr/src/app/

RUN npm install -g @angular/cli@1.7.3
RUN npm install
# Copy config files
EXPOSE 3000

# Start app through npm
#RUN ng serve --host 0.0.0.0 -D
ENTRYPOINT ["/bin/bash", "-c", "npm start"]


