##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GS_Sim
ConfigurationName      :=Debug
WorkspacePath          :=/home/03_Linux/01_gs4cubesat
ProjectPath            :=/home/03_Linux/01_gs4cubesat/C++Server/GS_Sim
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=03/06/19
CodeLitePath           :=/home/ajfg/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./bin/Debug/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GS_Sim.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)pthread $(LibrarySwitch)boost_system $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "zmq" "pthread" "boost_system" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall -std=c++11 -fexceptions -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/03_Linux/01_gs4cubesat/C++Server/Common/bin/Debug:/home/03_Linux/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug


$(IntermediateDirectory)/.d:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/03_Linux/01_gs4cubesat/C++Server/GS_Sim/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM src/main.cpp

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix): src/json11.cpp $(IntermediateDirectory)/src_json11.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/03_Linux/01_gs4cubesat/C++Server/GS_Sim/src/json11.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_json11.cpp$(DependSuffix): src/json11.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_json11.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_json11.cpp$(DependSuffix) -MM src/json11.cpp

$(IntermediateDirectory)/src_json11.cpp$(PreprocessSuffix): src/json11.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_json11.cpp$(PreprocessSuffix) src/json11.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/


