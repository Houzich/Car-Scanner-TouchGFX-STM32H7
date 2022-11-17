# Helper macros to convert spaces into question marks and back again
e := 
sp := $(e) $(e)
qs = $(subst ?,$(sp),$1)
sq = $(subst $(sp),?,$1)


# Finds files that matches the specified pattern. The directory list
# is searched recursively. It is safe to invoke this function with an
# empty list of directories.
#
# Param $(1): List of directories to search
# Param $(2): The file pattern to search for
# define find
# 	$(foreach dir,$(1),$(foreach d,$(wildcard $(dir)/*),\
# 		$(call find,$(d),$(2))) $(wildcard $(dir)/$(strip $(2))))
# endef
# unexport find

# Get name of this Makefile (avoid getting word 0 and a starting space)
makefile_name := $(wordlist 1,1000,$(MAKEFILE_LIST))

# Get path of this Makefile
makefile_path := $(call qs,$(dir $(call sq,$(abspath $(call sq,$(makefile_name))))))

# Get path where the Application is
application_path := $(call qs,$(abspath $(call sq,$(makefile_path)../..)))
# main_path := $(call qs,$(abspath $(call sq,$(makefile_path)../../..)))

data_path := $(call qs,$(abspath $(call sq,$(makefile_path)../../../Data)))
data_files := ../Data/CarModels.cpp ../Data/Cars.cpp ../Data/Data.cpp ../Data/DiagnosticsClass.cpp ../Data/DiagnosticsDataClass.cpp ../Data/Widget.cpp

# wifi_path := $($(main_path)/WIFI/Network_Library/Includes)
# wifi_path := $(call qs,$(abspath $(call sq,$(makefile_path)../../../WIFI/Network_Library/Includes)))
# wifi_files := $(call find, $(wifi_path), *.h)

.PHONY: clean assets all

ifneq ($(words $(makefile_path))$(words $(MAKEFILE_LIST)),11)
all clean assets:
$(error Spaces not allowed in path)
else

ADDITIONAL_SOURCES :=  $(data_files)
ADDITIONAL_INCLUDE_PATHS :=  $(data_path)
ADDITIONAL_LIBRARY_PATHS :=  
ADDITIONAL_LIBRARIES := 
export ADDITIONAL_SOURCES ADDITIONAL_INCLUDE_PATHS ADDITIONAL_LIBRARY_PATHS ADDITIONAL_LIBRARIES

all: $(filter assets,$(MAKECMDGOALS))
all assets: $(filter clean,$(MAKECMDGOALS))
all clean assets:
	@$(MAKE) -r -f generated/simulator/gcc/Makefile -s $(MFLAGS) $@ -C "$(application_path)"
endif

