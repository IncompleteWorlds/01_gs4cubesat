#!/usr/bin/env python3

import pystache
import configparser

config = None


class Labels(object):
    def __init__(self, inLabels):
        self.labels = inLabels

    def MsgHeader(self):
        return self.labels['MsgHeader']
     
    def MsgErrorData(self):
        return self.labels['MsgErrorData']

    def StateVector(self):
        return self.labels['StateVector']

    def FdsEvent(self):
        return self.labels['FdsEvent']


# Read the configuration
def read_labels():
    global config

    labels={}

    sectionName='Labels'
    for key in config[sectionName]: 
        try: 
            print("###############################################")
            print("Key:               ", key)
            
            currentFileName = config.get(sectionName, key)
            print( "Processing file: ", currentFileName  )

            with open(currentFileName) as labelsFile:
                currentTemplate = labelsFile.read()

            # Remove namespace
            # Remove this line:   "namespace":  "com.incomplete.cubegs.common.avro.messages",
            i = currentTemplate.find('namespace')
            if i != -1:
                firstComma = currentTemplate.rfind(',', 0, i)
                lastComma = currentTemplate.find(',', i)

#                print(firstComma, lastComma)

                tmpTemplate = list(currentTemplate)
                for c in range(firstComma, lastComma):
                    tmpTemplate[c] = ' '
                    
                currentTemplate = "".join(tmpTemplate)

                print(currentTemplate)            

            if (len(currentTemplate) != 0):
                labels[key] = currentTemplate
                print("     OK")
                print("")

        except Exception as e:
            print("ERROR: Processing file: " + currentFileName)
            print(e)
            print("****** File IGNORED ******")

    return labels


ACTUALIZAR CON RESPECTO A LOS NUEVOS DIRECTORIOS
COMPLETE GET_EVENTS

def process_schemas():
    global config

    config = configparser.ConfigParser()
    config.optionxform = lambda option: option
    config.read('labels.cfg')

    # Read labels
    labels = read_labels()

    labelsList = Labels(labels)

    # Mustache renderer
    renderer = pystache.Renderer()

    sectionName='Schemas'
    for key in config[sectionName]: 
        try: 
            print("*****************************************")
            print("Message: ", key)
            currentFileName = config.get(sectionName, key)
            print( "Processing template file: ", currentFileName  )

            with open(currentFileName) as templateFile:
                currentTemplate = templateFile.read()

            # Update template
            newTemplate = renderer.render(currentTemplate, labelsList)
            print( newTemplate )

            # Write new file
            outputFileName = currentFileName.replace("template", "json")
            with open(outputFileName, "w") as outputFile:
                outputFile.write(newTemplate)


        except Exception as e:
            print("ERROR: Processing file: " + currentFileName)
            print(e)
            print("****** File IGNORED ******")





if __name__ == '__main__':
    process_schemas()

    print("******************************** ")
    print("       WARNING   WARNING ")
    print("******************************** ")
    print("")
    print("Are the following items updated?")
    print("  - compile_schemas.py updated with respect to the latest fields' names")
    print("  - labels in labels.cfg")
    print("  - template files")
    print("")
    print("If not please, update and re-run")


