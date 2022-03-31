##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=LayersTmDecoder
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/LayersTmDecoder
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=11/11/19
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="LayersTmDecoder.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security/include 
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
CXXFLAGS :=  -g -O0 -Wall -std=c++11 -fexceptions -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_LayersTmDecoder.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LayersTmDecoderModuleManager.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_LayersTmDecoder.cpp$(ObjectSuffix): src/LayersTmDecoder.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/LayersTmDecoder/src/LayersTmDecoder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LayersTmDecoder.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LayersTmDecoder.cpp$(PreprocessSuffix): src/LayersTmDecoder.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LayersTmDecoder.cpp$(PreprocessSuffix) src/LayersTmDecoder.cpp

$(IntermediateDirectory)/src_LayersTmDecoderModuleManager.cpp$(ObjectSuffix): src/LayersTmDecoderModuleManager.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/LayersTmDecoder/src/LayersTmDecoderModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LayersTmDecoderModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LayersTmDecoderModuleManager.cpp$(PreprocessSuffix): src/LayersTmDecoderModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LayersTmDecoderModuleManager.cpp$(PreprocessSuffix) src/LayersTmDecoderModuleManager.cpp

##
## Clean
##
clean:
	$(RM) -r ./Debug/


