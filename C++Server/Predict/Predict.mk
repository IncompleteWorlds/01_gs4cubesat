##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Predict
ConfigurationName      :=Debug
WorkspacePath          :="/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat"
ProjectPath            :="/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Predict"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=16/08/19
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
ObjectsFileList        :="Predict.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)curses 
ArLibs                 :=  "curses" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/nxjson.c$(ObjectSuffix) $(IntermediateDirectory)/predict.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/nxjson.c$(ObjectSuffix): nxjson.c $(IntermediateDirectory)/nxjson.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Predict/nxjson.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nxjson.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nxjson.c$(DependSuffix): nxjson.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nxjson.c$(ObjectSuffix) -MF$(IntermediateDirectory)/nxjson.c$(DependSuffix) -MM nxjson.c

$(IntermediateDirectory)/nxjson.c$(PreprocessSuffix): nxjson.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nxjson.c$(PreprocessSuffix) nxjson.c

$(IntermediateDirectory)/predict.c$(ObjectSuffix): predict.c $(IntermediateDirectory)/predict.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/alberto/LXLE Linux/home/alberto/Projects/01_gs4cubesat/C++Server/Predict/predict.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/predict.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/predict.c$(DependSuffix): predict.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/predict.c$(ObjectSuffix) -MF$(IntermediateDirectory)/predict.c$(DependSuffix) -MM predict.c

$(IntermediateDirectory)/predict.c$(PreprocessSuffix): predict.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/predict.c$(PreprocessSuffix) predict.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


