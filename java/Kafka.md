# Deploy Kafka In Linux

## ceate a kafka user
``` shell 
$ sudo useradd kafka -m         # add kafka user
$ sudo passwd kafka             # set the password
$ sudo useradd kafka sudo       # add user to sudo group
```

## download and install kafka in user "kafka"
``` shell
$ su -l kafka
$ curl "http://www-eu.apache.org/dist/kafka/1.1.0/kafka_2.12-1.1.0.tgz" -o ~/Downloads/kafka.tgz            # download
$ mkdir ~/kafka && cd ~/kafka
$ tar -xvzf ~/Downloads/kafka.tgz -strip 1
```

## config kafka
``` shell
$ vim ~/kafka/config/server.properties
# delete.topic.enable = true
```

## config systemd unit file for both zookeeper and kafka
``` shell
$ sudo vim /etc/systemd/system/zookeeper.service
##################
## [Unit]
## Requires=network.target remote-fs.target
## After=network.target remote-fs.target
## 
## [Service]
## Type=simple
## User=kafka
## ExecStart=/home/kafka/kafka/bin/zookeeper-server-start.sh /home/kafka/kafka/## config/zookeeper.properties
## ExecStop=/home/kafka/kafka/bin/zookeeper-server-stop.sh
## Restart=on-abnormal
## 
## [Install]
## WantedBy=multi-user.target
###################

$ sudo vim /etc/systemd/system/kafka.service
###################
## [Unit]
## Requires=zookeeper.service
## After=zookeeper.service
## 
## [Service]
## Type=simple
## User=kafka
## ExecStart=/bin/sh -c '/home/kafka/kafka/bin/kafka-server-start.sh /home/k #afka/#kafka/config/server.properties > /home/kafka/kafka/kafka.log 2>&1'
## ExecStop=/home/kafka/kafka/bin/kafka-server-stop.sh
## Restart=on-abnormal
## 
## [Install]
## WantedBy=multi-user.target
###################
```

## start the service and test
``` shell
$ sudo systemctl enable kafka
$ sudo service kafka start
$ sudo service kafka status

## test
## create a topic
$ ~/kafka/bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic TutorialTopic      
## public a message to topic 
$ echo "Hello, World" | ~/kafka/bin/kafka-console-producer.sh --broker-list localhost:9092 --topic TutorialTopic > /dev/null
## consume the message
$ ~/kafka/bin/kafka-console-consumer.sh --bootstrap-server localhost:9092 --topic TutorialTopic --from-beginning
```

## further
* kafkaT
* multi-node cluster
* restrict kafka user

## Reference
https://www.digitalocean.com/community/tutorials/how-to-install-apache-kafka-on-ubuntu-18-04


# Kafka

## What is kafka?
* Message Queue, pub/sub
* when BCD require data from A, A don't need to configure BCE, just send data to MQ, then BCD go get the data from MQ
* Ads: decoupling, asynchronize, clipping
* Dis: availability(easy to down), complexity, consistency
