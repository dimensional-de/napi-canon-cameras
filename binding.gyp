{
    "defines": [
        "NAPI_VERSION=<(napi_build_version)",
    ],
    "targets": [
        {
            "target_name": "canon_api",
            'cflags!': [ '-fno-exceptions' ],
            'cflags_cc!': [ '-fno-exceptions' ],
            'defines': [ 'NAPI_ENABLE_CPP_EXCEPTIONS' ],
            'msvs_settings': {
                'VCCLCompilerTool': {
                   'ExceptionHandling': 1,
                   'AdditionalOptions': [ '-std:c++17' ]
                }
            },
            "sources": [
                "./src/library/api-error.cc",
                "./src/library/api-identifier.cc",
                "./src/library/base64.cc",
                "./src/library/camera.cc",
                "./src/library/camera-browser.cc",
                "./src/library/camera-file.cc",
                "./src/library/camera-property.cc",
                "./src/library/camera-api.cc",
                "./src/library/directory.cc",
                "./src/library/labels.cc",
                "./src/library/object-event.cc",
                "./src/library/option.cc",
                "./src/library/aperture.cc",
                "./src/library/exposure-compensation.cc",
                "./src/library/flag.cc",
                "./src/library/image-quality.cc",
                "./src/library/iso-sensitivity.cc",
                "./src/library/shutter-speed.cc",
                "./src/library/state-event.cc",
                "./src/library/utility.cc",
                "./src/library/volume.cc",
            ],
            "include_dirs": [
                "./src",
                "<(module_root_dir)/third_party/EDSDK/Windows/EDSDK/Header",
                "<!(node -p \"require('node-addon-api').include_dir\")"
            ],
            "conditions": [
                [
                    "OS==\"win\" and target_arch==\"x64\"",
                    {
                        "libraries": [
                          "../third_party/EDSDK/Windows/EDSDK_64/Library/EDSDK.lib"
                        ],
                        "copies": [
                            {
                                "destination": "<(PRODUCT_DIR)",
                                "files": [
                                    "<(module_root_dir)/third_party/EDSDK/Windows/EDSDK_64/Dll/EDSDK.dll",
                                    "<(module_root_dir)/third_party/EDSDK/Windows/EDSDK_64/Dll/EdsImage.dll"
                                ]
                            }
                        ]
                    }
                ],
                [
                    "OS==\"win\" and target_arch==\"ia32\"",
                    {
                        "libraries": [
                          "../third_party/EDSDK/Windows/EDSDK/Library/EDSDK.lib"
                        ],
                        "copies": [
                            {
                                "destination": "<(PRODUCT_DIR)",
                                "files": [
                                    "<(module_root_dir)/third_party/EDSDK/Windows/EDSDK/Dll/EDSDK.dll",
                                    "<(module_root_dir)/third_party/EDSDK/Windows/EDSDK/Dll/EdsImage.dll"
                                ]
                            }
                        ]
                    }
                ]
           ]
        }
    ],
}
