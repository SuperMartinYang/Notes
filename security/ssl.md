# SSLv3 (TLS)

## Definition
* Security on Transport layer, with compress and encryption, prevent the application data visible in the routing process

## Protocol Suit and Packet
* protocol stack
![protocol stack](ssl_protocol.png)

* form packet
![packet info](ssl_form_packet.png)

    * In record header, there's some informaiton
        1. message type: handshake message / cipher spec message
        1. version
        1. block length

## Key Exchange 
* Diagram from net
![key exchange](ssl_key_exchange.png)

* Diagram of my own understanding
![my_own_understanding](http://www.plantuml.com/plantuml/proxy?src=https://raw.github.com/supermartinyang/Notes/master/security/ssl_key_exchange.txt)

## SSL VPN
* over application level, no need extra hardware
* data are encrypted until get to target, rather than site (compare with IPSec VPN)