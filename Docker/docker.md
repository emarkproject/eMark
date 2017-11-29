### Docker container ###
Running your eMarkd within an isolated container for quick setup and ease of use in development envoriment. 

Install docker

    apt-get install docker
    
Create your working directory for storing persistent data
    
    mkdir ~/.eMark
    
Specify config variables in eMark.conf file. [NOTE: you may want to change user and pass]

    echo "rpcuser=eMarkUser\r\nrpcpassword=2ue3829k10ur839f201uf38902uk1r893f2\r\nrpcport=6666" > ~/.eMark/eMark.conf

Navigate to the Docker folder and build the docker container from within the Docker directory
    
    docker build . -t emark
    
Run the docker container 
    
    docker run -d -v ~/.eMark:/root/.eMark -p 6666:6666 emark:latest
   
Your host should now be listening on port 6666 for rpc calls. 

Another option is to connect to your container using bash. Fetch the ``` CONTAINER_ID ``` with the ```docker ps``` command and run ```docker exec```

    docker exec -it CONTAINER_ID bash
    
The deamon application is located in ```/emark/src```

Questions? Contact me at massimo@wenusch.nl