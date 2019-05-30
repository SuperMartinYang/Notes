# Commands

## Image
``` sh
# build image on our own
$ docker build -t tag-name <some location contains Dockerfile>
# show all images
$ docker images
# rm image
$ docker image rm <image name / hash>
# pull image
$ docker pull <image name>
# delete all image
$ docker rm $(docker image ls -q)
# inspect image
$ docker image inspect <image name>

``` 

## Container
``` sh
# run container from image
$ docker container run [args] <image name>
    --net           # set network
    -v              # volume / mounting
    -p              # port mapping
    --net-alias     # set alias in network
    -d              # detach
# rm container
$ docker container rm -f $(docker container ls -q)
# inspect container
$ docker container inspect <container name>
# follow logs
$ docker container logs -f <container name>
# run bash in container
$ docker container exec -it <container name> bash
```

## Network
``` sh
# create network
$ docker network create <network name>
    -d              # set driver
# rm network
$ docker network rm <network name>
```

## Volume
``` sh
# remove volume
$ docker volume rm <volume name> 
```

## Docker-machine
``` sh
# create a machine, like default
$ docker-machine create <machine name>
# start a machine
$ docker-machine start <machine name>
# connect to machine
$ docker-machine ssh <machine name>
# inspect
$ docker-machine inspect <machine name>
```

## Docker-compose
``` sh
# run a compose, always named docker-compose.yml
$ docker-compose up
# shutdown the compose
$ docker-compose down
    --rmi <type>    # rm image at the same time
    -v              # rm volume at the same time
```

## Swarm
``` sh
# init the swarm
$ docker swarm init
    --advertise-addr <ip>
# generate command for manager join
$ docker swarm join-token manager
# join the swarm (use the command)
$ docker swarm join --token <generated token> <ip:port>

# view node in manager
$ docker node ls
# promote a node
$ docker node promote <node name>

# create service 
$ docker service create <image name>
    -d                  # detach
    -e                  # environment
    -p                  # map the port
    --name              # assign a name
    --replicas <cnt>    # create multi nodes
    --network <network> # set network
# rm service
$ docker service rm <service name> 

# start docker compose file by using stack
$ docker stack deploy -c <filename> <app name>
# rm stack services
$ docker stack rm <app name>
```

