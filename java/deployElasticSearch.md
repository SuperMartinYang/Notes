# Deploy ElasticSearch In Linux

## download and install package
``` shell
wget https://download.elastic.co/elasticsearch/release/org/elasticsearch/distribution/deb/elasticsearch/2.3.1/elasticsearch-2.3.1.deb
sudo dpkg -i elasticsearch-2.3.1.deb
```

## config the ElasticSearch
* /etc/elasticserach/elasticsearch.yml -> for service configuration
* /etc/elasticsearch/logging.yml -> for log configuration
* modify the service config
    
    * cluster.name = app
    * node.name = "aa"
    * node.master = false
    * node.data = true
    * path.data = /self/data/
* config the service which can start and stop autoly
    ``` shell
    systemctl enable elasticsearch.service
    ```
    
## test the service
``` shell
curl -X GET "http://localhost:9200/"
```

