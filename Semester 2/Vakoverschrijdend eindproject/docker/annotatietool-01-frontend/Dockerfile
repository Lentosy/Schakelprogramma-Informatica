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
RUN npm rebuild node-sass --force
# Copy config files
EXPOSE 4200

# Start app through npm
ENTRYPOINT ["/bin/bash", "-c", "ng serve --host 0.0.0.0 --disable-host-check"]
#RUN ng serve --host 0.0.0.0


