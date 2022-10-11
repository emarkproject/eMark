### Docker container ###
Running your eMarkd within an isolated container for quick setup and ease of use in development environment.

Install docker

    https://docs.docker.com/engine/install/

Create your working directory for storing persistent data

    mkdir ~/.eMark

Specify config variables in eMark.conf file. [NOTE: you may want to change user and pass]

    echo "rpcuser=eMarkUser\r\nrpcpassword=2ue3829k10ur839f201uf38902uk1r893f2\r\nrpcport=7777" > ~/.eMark/eMark.conf

Navigate to the Docker folder and build the docker container from within the Docker directory

    docker build . -t emark

Run the docker container

    docker run -d -v ~/.eMark:/root/.eMark -p 127.0.0.1:7777:7777 5556:5556 emark:latest

Your host should now be listening on port 7777 for rpc calls.


The daemon application is located in ```/emark/src```
