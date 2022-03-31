##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Tools
ConfigurationName      :=Debug
WorkspacePath          :=/home/alberto/Projects/01_gs4cubesat/C++Server
ProjectPath            :=/home/alberto/Projects/01_gs4cubesat/C++Server/Tools
IntermediateDirectory  :=./obj/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alberto
Date                   :=22/03/20
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
OutputFile             :=./bin/Debug/$(ProjectName)
Preprocessors          :=
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
Libs                   := $(LibrarySwitch)Common $(LibrarySwitch)Security_Access_Control $(LibrarySwitch)avrocpp $(LibrarySwitch)zmq $(LibrarySwitch)SQLiteCpp $(LibrarySwitch)sqlite3 $(LibrarySwitch)pthread $(LibrarySwitch)log4cpp 
ArLibs                 :=  "Common" "Security_Access_Control" "avrocpp" "zmq" "SQLiteCpp" "sqlite3" "pthread" "log4cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)../Common/bin/Debug $(LibraryPathSwitch)../Security_Access_Control/bin/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall -fexceptions  -Weffc++ $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=$LD_LIBRARY_PATH:/home/alberto/Projects/01_gs4cubesat/C++Server/Common/bin/Debug:/home/alberto/Projects/01_gs4cubesat/C++Server/Security_Access_Control/bin/Debug
Objects0=$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix): src/messages/FileTransferMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/FileTransferMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(PreprocessSuffix): src/messages/FileTransferMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_FileTransferMessage.cpp$(PreprocessSuffix) src/messages/FileTransferMessage.cpp

$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix): src/messages/GetFrameTypesMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetFrameTypesMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(PreprocessSuffix): src/messages/GetFrameTypesMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetFrameTypesMessage.cpp$(PreprocessSuffix) src/messages/GetFrameTypesMessage.cpp

$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix): src/messages/GetLayerParametersMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetLayerParametersMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(PreprocessSuffix): src/messages/GetLayerParametersMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetLayerParametersMessage.cpp$(PreprocessSuffix) src/messages/GetLayerParametersMessage.cpp

$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix): src/messages/GetMissionMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(PreprocessSuffix): src/messages/GetMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetMissionMessage.cpp$(PreprocessSuffix) src/messages/GetMissionMessage.cpp

$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix): src/messages/GetSatelliteMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetSatelliteMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(PreprocessSuffix): src/messages/GetSatelliteMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetSatelliteMessage.cpp$(PreprocessSuffix) src/messages/GetSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix): src/messages/ImportScDbMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/ImportScDbMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(PreprocessSuffix): src/messages/ImportScDbMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_ImportScDbMessage.cpp$(PreprocessSuffix) src/messages/ImportScDbMessage.cpp

$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix): src/messages/ToolsLoginMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/ToolsLoginMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(PreprocessSuffix): src/messages/ToolsLoginMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_ToolsLoginMessage.cpp$(PreprocessSuffix) src/messages/ToolsLoginMessage.cpp

$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix): src/messages/AddMissionMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/AddMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(PreprocessSuffix): src/messages/AddMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddMissionMessage.cpp$(PreprocessSuffix) src/messages/AddMissionMessage.cpp

$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix): src/messages/AddSatelliteMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/AddSatelliteMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(PreprocessSuffix): src/messages/AddSatelliteMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddSatelliteMessage.cpp$(PreprocessSuffix) src/messages/AddSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix): src/messages/GetSubsystemMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(PreprocessSuffix): src/messages/GetSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetSubsystemMessage.cpp$(PreprocessSuffix) src/messages/GetSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix): src/messages/UpdateSubsystemMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/UpdateSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(PreprocessSuffix): src/messages/UpdateSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_UpdateSubsystemMessage.cpp$(PreprocessSuffix) src/messages/UpdateSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix): src/messages/RemoveMissionLayerMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/RemoveMissionLayerMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(PreprocessSuffix): src/messages/RemoveMissionLayerMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveMissionLayerMessage.cpp$(PreprocessSuffix) src/messages/RemoveMissionLayerMessage.cpp

$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix): src/messages/RemoveSubsystemMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/RemoveSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(PreprocessSuffix): src/messages/RemoveSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveSubsystemMessage.cpp$(PreprocessSuffix) src/messages/RemoveSubsystemMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix): src/messages/UpdateMissionMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/UpdateMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(PreprocessSuffix): src/messages/UpdateMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_UpdateMissionMessage.cpp$(PreprocessSuffix) src/messages/UpdateMissionMessage.cpp

$(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix): src/ToolsDatabase.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/ToolsDatabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ToolsDatabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ToolsDatabase.cpp$(PreprocessSuffix): src/ToolsDatabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ToolsDatabase.cpp$(PreprocessSuffix) src/ToolsDatabase.cpp

$(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix): src/tools_main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/tools_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tools_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tools_main.cpp$(PreprocessSuffix): src/tools_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tools_main.cpp$(PreprocessSuffix) src/tools_main.cpp

$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix): src/ExcelFormat.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/ExcelFormat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ExcelFormat.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ExcelFormat.cpp$(PreprocessSuffix): src/ExcelFormat.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ExcelFormat.cpp$(PreprocessSuffix) src/ExcelFormat.cpp

$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix): src/ToolsMessageProcessor.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/ToolsMessageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(PreprocessSuffix): src/ToolsMessageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ToolsMessageProcessor.cpp$(PreprocessSuffix) src/ToolsMessageProcessor.cpp

$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix): src/messages/RemoveSatelliteMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/RemoveSatelliteMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(PreprocessSuffix): src/messages/RemoveSatelliteMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveSatelliteMessage.cpp$(PreprocessSuffix) src/messages/RemoveSatelliteMessage.cpp

$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix): src/messages/GetDefaultMissionLayersMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetDefaultMissionLayersMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(PreprocessSuffix): src/messages/GetDefaultMissionLayersMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetDefaultMissionLayersMessage.cpp$(PreprocessSuffix) src/messages/GetDefaultMissionLayersMessage.cpp

$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix): src/messages/AddMissionLayerMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/AddMissionLayerMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(PreprocessSuffix): src/messages/AddMissionLayerMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddMissionLayerMessage.cpp$(PreprocessSuffix) src/messages/AddMissionLayerMessage.cpp

$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix): src/ToolsModuleManager.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/ToolsModuleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ToolsModuleManager.cpp$(PreprocessSuffix): src/ToolsModuleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ToolsModuleManager.cpp$(PreprocessSuffix) src/ToolsModuleManager.cpp

$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix): src/BasicExcel.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/BasicExcel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_BasicExcel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_BasicExcel.cpp$(PreprocessSuffix): src/BasicExcel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_BasicExcel.cpp$(PreprocessSuffix) src/BasicExcel.cpp

$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix): src/messages/RemoveMissionMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/RemoveMissionMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(PreprocessSuffix): src/messages/RemoveMissionMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RemoveMissionMessage.cpp$(PreprocessSuffix) src/messages/RemoveMissionMessage.cpp

$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix): src/messages/UpdateSatellieMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/UpdateSatellieMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(PreprocessSuffix): src/messages/UpdateSatellieMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_UpdateSatellieMessage.cpp$(PreprocessSuffix) src/messages/UpdateSatellieMessage.cpp

$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix): src/messages/RegisterUserMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/RegisterUserMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(PreprocessSuffix): src/messages/RegisterUserMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_RegisterUserMessage.cpp$(PreprocessSuffix) src/messages/RegisterUserMessage.cpp

$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix): src/messages/GetMissionLayersMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/GetMissionLayersMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(PreprocessSuffix): src/messages/GetMissionLayersMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_GetMissionLayersMessage.cpp$(PreprocessSuffix) src/messages/GetMissionLayersMessage.cpp

$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix): src/messages/AddSubsystemMessage.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alberto/Projects/01_gs4cubesat/C++Server/Tools/src/messages/AddSubsystemMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(PreprocessSuffix): src/messages/AddSubsystemMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_messages_AddSubsystemMessage.cpp$(PreprocessSuffix) src/messages/AddSubsystemMessage.cpp

##
## Clean
##
clean:
	$(RM) -r ./obj/Debug/


