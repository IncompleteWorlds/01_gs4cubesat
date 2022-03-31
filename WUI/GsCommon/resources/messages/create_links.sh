#!/bin/bash

rm AvroTypes.avro data_model messages last_none.json  compile_java.sh

ln -s ../../../messages/AvroTypes.avro   .

ln -s ../../../messages/data_model/ .

ln -s ../../../messages/messages/ .

ln -s ../../../messages/last_none.json  .

ln -s ../../../messages/compile_java.sh  .

