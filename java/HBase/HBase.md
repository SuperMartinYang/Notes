# HBase

## Concept
* HBase is NoSQL, can run on top of HDFS, or local file system
* HBase has column family (CF)

    | ID | CF1 | CF2 |
    | -------------- | --------------- | --------------- |
    | 1 | account {"account": "hello"} <br /> pwd {"password": "111"} | age {"age": 10} <br> education {"edu": "MSIS"} |

* store CF in HFile
* depend on zookeeper to get HA

![diagrame for HBase with zookeeper](http://www.plantuml.com/plantuml/proxy?src=https://raw.github.com/supermartinyang/Notes/master/java/HBase/hbase-zookeeper.txt)

## Usecase
* real time retrieve data, compare to hive which is better at process data in a date range but slower. 
* just provide API, no HQL, Hive have HQL, so we can use Pheonix to provide HQL
* good for structure data
* column oriented storage
* PB scale

## Deploy in linux

