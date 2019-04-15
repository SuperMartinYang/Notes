# Config java in linux

## Install with apt
``` shell
sudo apt-get install default-jdk
```

## create a like to jdk
``` shell
link java-1.8.0-openjdk-amd64 main-java
```

## set $JAVA_HOME
``` shell
echo "$JAVA_HOME=/usr/lib/jvm/main-java" >> /etc/environment
source /etc/environment 
```

## test java
``` shell
java --version
```