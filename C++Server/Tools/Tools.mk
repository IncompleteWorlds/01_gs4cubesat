##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Tools
ConfigurationName      :=Release
WorkspacePath          :=/home/alberto/Documents/01_gs4cubesat
ProjectPath            :=/home/alberto/Documents/01_gs4cubesat/C++Server/Tools
IntermediateDirectory  :=./obj/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=02/07/18
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
OutputFile             :=./bin/Release/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Tools.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)include/messages $(IncludeSwitch)../Common/include $(IncludeSwitch)../Security_Access_Control/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)pthread $(LibrarySwitch)log4cpp $(LibrarySwitch)zmq $(LibrarySwitch)avrocpp 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "zmq" "SQLiteCpp" "sqlite3" "pthread" "log4cpp" "zmq" "avrocpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Release $(LibraryPathSwitch)../Security_Access_Control/bin/Release 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -std=c++11 -Wall -fexceptions -m64 -Weffc++ $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Documents/01_gs4cubesat/C++Server/Common/bin/Release:/home/alberto/Documents/01_gs4cubesat/C++Server/Security_Access_Control/bin/Release
Objects0=$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) 



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
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release


$(IntermediateDirectory)/.d:
	@test -d ./obj/Release || $(MakeDirCommand) ./obj/Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix): src/messages/FileTransferMessage.cpp $(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/FileTransferMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(DependSuffix): src/messages/FileTransferMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(DependSuffix) -MM src/messages/FileTransferMessage.cpp

$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(PreprocessSuffix): src/messages/FileTransferMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(PreprocessSuffix) src/messages/FileTransferMessage.cpp

$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix): src/messages/GetLayerParametersMessage.cpp $(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetLayerParametersMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(DependSuffix): src/messages/GetLayerParametersMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(DependSuffix) -MM src/messages/GetLayerParametersMessage.cpp

$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(PreprocessSuffix): src/messages/GetLayerParametersMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(PreprocessSuffix) src/messages/GetLayerParametersMessage.cpp

$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix): src/messages/GetMissionMessage.cpp $(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(DependSuffix): src/messages/GetMissionMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(DependSuffix) -MM src/messages/GetMissionMessage.cpp

$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(PreprocessSuffix): src/messages/GetMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(PreprocessSuffix) src/messages/GetMissionMessage.cpp

$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix): src/messages/ToolsLoginMessage.cpp $(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/ToolsLoginMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(DependSuffix): src/messages/ToolsLoginMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(DependSuffix) -MM src/messages/ToolsLoginMessage.cpp

$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(PreprocessSuffix): src/messages/ToolsLoginMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(PreprocessSuffix) src/messages/ToolsLoginMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix): src/messages/UpdateSatellieMessage.cpp $(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/UpdateSatellieMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(DependSuffix): src/messages/UpdateSatellieMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(DependSuffix) -MM src/messages/UpdateSatellieMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(PreprocessSuffix): src/messages/UpdateSatellieMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(PreprocessSuffix) src/messages/UpdateSatellieMessage.cpp

$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix): src/messages/GetSatelliteMessage.cpp $(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetSatelliteMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(DependSuffix): src/messages/GetSatelliteMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(DependSuffix) -MM src/messages/GetSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(PreprocessSuffix): src/messages/GetSatelliteMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(PreprocessSuffix) src/messages/GetSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix): src/messages/UpdateMissionMessage.cpp $(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/UpdateMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(DependSuffix): src/messages/UpdateMissionMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(DependSuffix) -MM src/messages/UpdateMissionMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(PreprocessSuffix): src/messages/UpdateMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(PreprocessSuffix) src/messages/UpdateMissionMessage.cpp

$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix): src/messages/GetSubsystemMessage.cpp $(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(DependSuffix): src/messages/GetSubsystemMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(DependSuffix) -MM src/messages/GetSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(PreprocessSuffix): src/messages/GetSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(PreprocessSuffix) src/messages/GetSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix): src/messages/RemoveSatelliteMessage.cpp $(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/RemoveSatelliteMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(DependSuffix): src/messages/RemoveSatelliteMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(DependSuffix) -MM src/messages/RemoveSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(PreprocessSuffix): src/messages/RemoveSatelliteMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(PreprocessSuffix) src/messages/RemoveSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix): src/messages/GetDefaultMissionLayersMessage.cpp $(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetDefaultMissionLayersMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(DependSuffix): src/messages/GetDefaultMissionLayersMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(DependSuffix) -MM src/messages/GetDefaultMissionLayersMessage.cpp

$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(PreprocessSuffix): src/messages/GetDefaultMissionLayersMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(PreprocessSuffix) src/messages/GetDefaultMissionLayersMessage.cpp

$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix): src/messages/GetFrameTypesMessage.cpp $(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetFrameTypesMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(DependSuffix): src/messages/GetFrameTypesMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(DependSuffix) -MM src/messages/GetFrameTypesMessage.cpp

$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(PreprocessSuffix): src/messages/GetFrameTypesMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(PreprocessSuffix) src/messages/GetFrameTypesMessage.cpp

$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix): src/messages/AddMissionLayerMessage.cpp $(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/AddMissionLayerMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(DependSuffix): src/messages/AddMissionLayerMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(DependSuffix) -MM src/messages/AddMissionLayerMessage.cpp

$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(PreprocessSuffix): src/messages/AddMissionLayerMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(PreprocessSuffix) src/messages/AddMissionLayerMessage.cpp

$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix): src/messages/GetMissionLayersMessage.cpp $(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/GetMissionLayersMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(DependSuffix): src/messages/GetMissionLayersMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(DependSuffix) -MM src/messages/GetMissionLayersMessage.cpp

$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(PreprocessSuffix): src/messages/GetMissionLayersMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(PreprocessSuffix) src/messages/GetMissionLayersMessage.cpp

$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix): src/messages/RegisterUserMessage.cpp $(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/RegisterUserMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(DependSuffix): src/messages/RegisterUserMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(DependSuffix) -MM src/messages/RegisterUserMessage.cpp

$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(PreprocessSuffix): src/messages/RegisterUserMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(PreprocessSuffix) src/messages/RegisterUserMessage.cpp

$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix): src/BasicExcel.cpp $(IntermediateDirectory)/src_BasicExcel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/BasicExcel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_BasicExcel.cpp$(DependSuffix): src/BasicExcel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_BasicExcel.cpp$(DependSuffix) -MM src/BasicExcel.cpp

$(IntermediateDirectory)/src_BasicExcel.cpp$(PreprocessSuffix): src/BasicExcel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_BasicExcel.cpp$(PreprocessSuffix) src/BasicExcel.cpp

$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix): src/messages/AddMissionMessage.cpp $(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/AddMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(DependSuffix): src/messages/AddMissionMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(DependSuffix) -MM src/messages/AddMissionMessage.cpp

$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(PreprocessSuffix): src/messages/AddMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(PreprocessSuffix) src/messages/AddMissionMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix): src/messages/RemoveSubsystemMessage.cpp $(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/RemoveSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(DependSuffix): src/messages/RemoveSubsystemMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(DependSuffix) -MM src/messages/RemoveSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(PreprocessSuffix): src/messages/RemoveSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(PreprocessSuffix) src/messages/RemoveSubsystemMessage.cpp

$(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix): src/ToolsDatabase.cpp $(IntermediateDirectory)/src_ToolsDatabase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/ToolsDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ToolsDatabase.cpp$(DependSuffix): src/ToolsDatabase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ToolsDatabase.cpp$(DependSuffix) -MM src/ToolsDatabase.cpp

$(IntermediateDirectory)/src_ToolsDatabase.cpp$(PreprocessSuffix): src/ToolsDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ToolsDatabase.cpp$(PreprocessSuffix) src/ToolsDatabase.cpp

$(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix): src/tools_main.cpp $(IntermediateDirectory)/src_tools_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/tools_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tools_main.cpp$(DependSuffix): src/tools_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_tools_main.cpp$(DependSuffix) -MM src/tools_main.cpp

$(IntermediateDirectory)/src_tools_main.cpp$(PreprocessSuffix): src/tools_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tools_main.cpp$(PreprocessSuffix) src/tools_main.cpp

$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix): src/messages/AddSatelliteMessage.cpp $(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/AddSatelliteMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(DependSuffix): src/messages/AddSatelliteMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(DependSuffix) -MM src/messages/AddSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(PreprocessSuffix): src/messages/AddSatelliteMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(PreprocessSuffix) src/messages/AddSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix): src/messages/RemoveMissionLayerMessage.cpp $(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/RemoveMissionLayerMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(DependSuffix): src/messages/RemoveMissionLayerMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(DependSuffix) -MM src/messages/RemoveMissionLayerMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(PreprocessSuffix): src/messages/RemoveMissionLayerMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(PreprocessSuffix) src/messages/RemoveMissionLayerMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix): src/messages/UpdateSubsystemMessage.cpp $(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/UpdateSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(DependSuffix): src/messages/UpdateSubsystemMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(DependSuffix) -MM src/messages/UpdateSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(PreprocessSuffix): src/messages/UpdateSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(PreprocessSuffix) src/messages/UpdateSubsystemMessage.cpp

$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix): src/ToolsModuleManager.cpp $(IntermediateDirectory)/src_ToolsModuleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/ToolsModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(DependSuffix): src/ToolsModuleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(DependSuffix) -MM src/ToolsModuleManager.cpp

$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(PreprocessSuffix): src/ToolsModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ToolsModuleManager.cpp$(PreprocessSuffix) src/ToolsModuleManager.cpp

$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix): src/ToolsMessageProcessor.cpp $(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/ToolsMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(DependSuffix): src/ToolsMessageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(DependSuffix) -MM src/ToolsMessageProcessor.cpp

$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(PreprocessSuffix): src/ToolsMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(PreprocessSuffix) src/ToolsMessageProcessor.cpp

$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix): src/messages/ImportScDbMessage.cpp $(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/ImportScDbMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(DependSuffix): src/messages/ImportScDbMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(DependSuffix) -MM src/messages/ImportScDbMessage.cpp

$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(PreprocessSuffix): src/messages/ImportScDbMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(PreprocessSuffix) src/messages/ImportScDbMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix): src/messages/RemoveMissionMessage.cpp $(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/RemoveMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(DependSuffix): src/messages/RemoveMissionMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(DependSuffix) -MM src/messages/RemoveMissionMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(PreprocessSuffix): src/messages/RemoveMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(PreprocessSuffix) src/messages/RemoveMissionMessage.cpp

$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix): src/messages/AddSubsystemMessage.cpp $(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/messages/AddSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(DependSuffix): src/messages/AddSubsystemMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(DependSuffix) -MM src/messages/AddSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(PreprocessSuffix): src/messages/AddSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(PreprocessSuffix) src/messages/AddSubsystemMessage.cpp

$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix): src/ExcelFormat.cpp $(IntermediateDirectory)/src_ExcelFormat.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Documents/01_gs4cubesat/C++Server/Tools/src/ExcelFormat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ExcelFormat.cpp$(DependSuffix): src/ExcelFormat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ExcelFormat.cpp$(DependSuffix) -MM src/ExcelFormat.cpp

$(IntermediateDirectory)/src_ExcelFormat.cpp$(PreprocessSuffix): src/ExcelFormat.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ExcelFormat.cpp$(PreprocessSuffix) src/ExcelFormat.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./obj/Release/


