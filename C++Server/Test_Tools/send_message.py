#!/usr/bin/env python
# coding: utf8 

# / usr / bin / python

import os
import sys
import time
import zmq
import json


"""
sock.send(part1, zmq.SNDMORE)
sock.send(part2, zmq.SNDMORE)
sock.send(part3, zmq.SNDMORE)
sock.send(final)
"""

import avro.schema
from   avro.datafile  import DataFileReader, DataFileWriter
from   avro.io        import DatumReader, DatumWriter
try:
  from cStringIO import StringIO
except ImportError:
  from StringIO import StringIO


message_code = -1
message_data_file = ""
req_scheme_file = ""
res_scheme_file = ""
ip_address = "127.0.0.1"
ip_port = "9000"


def run():
    context = zmq.Context()
    sock = context.socket(zmq.REQ)
    sock.connect("tcp://{}:{}".format(ip_address, ip_port))
       
    # Read the schema
    schemeFile = open(req_scheme_file, 'r')
    schemeData = schemeFile.read()
    schemeFile.close()
    
    # Trick. Remove last ',' (comma)
    """
    lenData = len(schemeData)
    i = lenData-1
    while i > 0:
        if schemeData[i] == ',':
            tmpData = schemeData[0:i-1]
            schemeData = tmpData
            break
        else:
            i = i-1
    """
    
    # Parse scheme
    schema = avro.schema.parse(schemeData)
    writer = avro.io.DatumWriter(schema)
    
    # Create encoder
    bytes_writer = StringIO()
    encoder = avro.io.BinaryEncoder(bytes_writer)
    
    # Read the message file    
    messageFile = open(message_data_file, 'r')
    messageData = messageFile.read()
    messageFile.close()
    
    #print "Debug: ",messageData

    jsonData = json.loads(messageData)

    # Create message
    writer.write(jsonData, encoder)
          

    raw_bytes = bytes_writer.getvalue()
    #print(len(raw_bytes))
    #print(type(raw_bytes))
    
    # Send message
    sock.send(message_code, zmq.SNDMORE)
    sock.send(raw_bytes)


    replyId, replyData = sock.recv_multipart()
    print "Reply data: %s [%s\]" % (replyId, replyData)
    
    print ':'.join(x.encode('hex') for x in replyData)
    
    
    if res_scheme_file != "none":
        # Read the schema
        schemeFile = open(res_scheme_file, 'r')
        resSchemeData = schemeFile.read()
        schemeFile.close()
        
        resSchema = avro.schema.parse(resSchemeData)
    
        # Create decoder
        bytes_reader = StringIO(replyData)
        decoder = avro.io.BinaryDecoder(bytes_reader)
        reader = avro.io.DatumReader(resSchemeData)
        
        xx = reader.read(decoder)
        print json.dumps(xx, sort_keys=True, indent=4, separators=(',', ': '))
          


# Format

# ./send_message.py 501 resources/data_msg_connect_ground_station.json   ../Common/resources/messages/msg_connect_ground_station.json   127.0.0.1    9020


if __name__ == '__main__':
    if len(sys.argv) < 7:
        print "Usage: "
        print "       send_message   message_code    message_data.json   req_scheme_file.json   {res_scheme_file.json | none}   ip_address  ip_port "
        print " "
    else:
        # Extract parameters
        message_code = sys.argv[1]
        message_data_file = sys.argv[2]
        req_scheme_file = sys.argv[3]
        res_scheme_file = sys.argv[4]
        ip_address = sys.argv[5]
        ip_port = sys.argv[6]
        
        if message_code < 0:
            print "ERROR: Invalid message code"
            sys.exit(-1)
            
        if len(message_data_file) <= 0:
            print "ERROR: Invalid message data file name"
            sys.exit(-1)
        
        if len(req_scheme_file) <= 0:
            print "ERROR: Invalid scheme file name"
            sys.exit(-1)
            
        if len(res_scheme_file) <= 0:
            print "ERROR: Invalid scheme file name"
            sys.exit(-1)
            
        run()
        