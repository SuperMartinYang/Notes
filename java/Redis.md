# Deploy Redis in Linux

## download redis and deploy
``` shell
sudo apt install redis-server
```

## config redis
* after the installation, the service will be autoly start, but only can be accessed by localhost
* configuration /etc/redis/redis.conf
    
    * bind 127.0.0.1 ::1 => bind 0.0.0.0 ::1

## test the service
``` shell
redis-cli -h <redis_addr> ping
```

# Redis