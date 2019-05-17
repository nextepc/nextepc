# What's NextEPC

NextEPC is an Open Source implementation of the 4G/5G 3GPP core network. NextEPC includes the Mobility Management Entity
(MME), Serving Gateway (SGW), Packet Data Network Gateway (PGW), Home Subscriber Server (HSS), and Policy and Charging
Rules Functions (PCRF).

NextEPC MME provides the S1 interfaces to the eNodeBs and S11 interface to SGW as well as S6a to the HSS.

NextEPC SGW implements the S11 interface which is connected to MME, and S5 interface to the PGW.

NextEPC PGW plays a role as an edge router in IP networks. It equipped with the S5 interface and  SGi interface towards
the Internet, and S7 interface to PCRF.

NextEPC HSS is the user subscription database.  It implements the S6a interface towards MME using the DIAMETER protocol.

NextEPC PCRF controls the policies and rules for QoS of LTE users and bearers. It provides the Gx interface to PGW.

# Installation and Configuration 

Please visit [NextEPC Opensource Project Website](https://nextepc.org).


## Support

Technical service and supports are available on [https://nextepc.com](https://nextepc.com).


## License

Opensource NextEPC files are made available under the terms of the GNU Affero General Public License (GNU AGPLv3).

