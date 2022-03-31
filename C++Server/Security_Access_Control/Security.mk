##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Security
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Documents/01_gs4cubesat
ProjectPath            :=/home/alberto/Documents/01_gs4cubesat/C++Server/Security_Access_Control
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=21/06/17
CodeLitePath           :=/home/alberto/.codelite
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
OutputFile             :=./bin/Debug/libSecurity_Access_Control.so
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Security.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)../Common/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -std=c++11 -Wall -fexceptions -fPIC -Weffc++ -m64 $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(ObjectSuffix) 



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
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/home/alberto/Documents/01_gs4cubesat/.build-debug"
	@echo rebuilt > "/home/alberto/Documents/01_gs4cubesat/.build-debug/Security"

MakeIntermediateDirs:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug


$(IntermediateDirectory)/.d:
	@test -d ./obj/Debug || $(MakeDirCommand) ./obj/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(ObjectSuffix): src/SecurityAccessIF.cpp $(IntermediateDirectory)/src_SecurityAccessIF.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Security_Access_Control/src/SecurityAccessIF.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(DependSuffix): src/SecurityAccessIF.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(DependSuffix) -MM src/SecurityAccessIF.cpp

$(IntermediateDirectory)/src_SecurityAccessIF.cpp$(PreprocessSuffix): src/SecurityAccessIF.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SecurityAccessIF.cpp$(PreprocessSuffix) src/SecurityAccessIF.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/


