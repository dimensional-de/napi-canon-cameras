{
    "variables": {
        "edsdk_version": "131520",
        "edsdk_directory%": "EDSDK"
    },
    "defines": [
        "NAPI_VERSION=<(napi_build_version)",
    ],
    "targets": [
        {
            "target_name": "canon_api",
            'cflags!': [ '-fno-exceptions' ],
            'cflags_cc!': [ '-fno-exceptions' ],
            'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
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
                "./src/library/output-device.cc",
                "./src/library/aperture.cc",
                "./src/library/exposure-compensation.cc",
                "./src/library/file-format.cc",
                "./src/library/flag.cc",
                "./src/library/image-quality.cc",
                "./src/library/iso-sensitivity.cc",
                "./src/library/shutter-speed.cc",
                "./src/library/state-event.cc",
                "./src/library/time-zone.cc",
                "./src/library/utility.cc",
                "./src/library/volume.cc",
            ],
            "include_dirs": [
                "./src",
                "<!(node -p \"require('node-addon-api').include_dir\")"
            ],
            "conditions": [
                [
                    "OS==\"win\"",
                    {
                        'msvs_settings': {
                            'VCCLCompilerTool': {
                            'ExceptionHandling': 1,
                            'AdditionalOptions': [ '-std:c++17' ]
                            }
                        }
                    }
                ],
                [
                    "OS==\"win\" and target_arch==\"x64\"",
                    {
                        "variables": {
                            "edsdk_directory": "EDSDKv<(edsdk_version)W"
                        },
                        "include_dirs": [
                            "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK/Header"
                        ],
                        "libraries": [
                          "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK_64/Library/EDSDK.lib"
                        ],
                        "copies": [
                            {
                                "destination": "<(PRODUCT_DIR)",
                                "files": [
                                    "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK_64/Dll/EDSDK.dll",
                                    "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK_64/Dll/EdsImage.dll"
                                ]
                            }
                        ]
                    }
                ],
                [
                    "OS==\"win\" and target_arch==\"ia32\"",
                    {
                        "variables": {
                            "edsdk_directory": "EDSDKv<(edsdk_version)W"
                        },
                        "include_dirs": [
                            "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK/Header"
                        ],
                        "libraries": [
                          "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK/Library/EDSDK.lib"
                        ],
                        "copies": [
                            {
                                "destination": "<(PRODUCT_DIR)",
                                "files": [
                                    "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK/Dll/EDSDK.dll",
                                    "<(module_root_dir)/third_party/<(edsdk_directory)/Windows/EDSDK/Dll/EdsImage.dll"
                                ]
                            }
                        ]
                    }
                ],
                [
                    "OS==\"mac\"",
                    {
                        "defines": [ '__MACOS__' ],
                        "variables": {
                            "edsdk_directory": "EDSDKv<(edsdk_version)M"
                        },
                        "include_dirs": [
                            "<(module_root_dir)/third_party/<(edsdk_directory)/macos/EDSDK/Header"
                        ],
                        "libraries": [
                          "<(module_root_dir)/third_party/<(edsdk_directory)/macos/EDSDK/Framework/EDSDK.framework"
                        ],
                        'xcode_settings': {
                            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                            'MACOSX_DEPLOYMENT_TARGET': '10.15',
                            'OTHER_CFLAGS': [
                                '-std=c++17',
                                '-Wno-ignored-attributes'
                            ],
                            'OTHER_LDFLAGS': [
                                '-Wl,-rpath,./prebuilds/darwin-x64/,-rpath,./node_modules/@dimensional/napi-canon-cameras/prebuilds/darwin-x64/',
                                '-F ../third_party/<(edsdk_directory)/macos/EDSDK/Framework/',
                                '-framework EDSDK'
                            ]
                        },
                        "copies": [
                            {
                                "destination": "<(PRODUCT_DIR)",
                                "files": [
                                    "<(module_root_dir)/third_party/<(edsdk_directory)/macos/EDSDK/Framework/EDSDK.Framework"
                                ]
                            }
                        ]
                    }
                ]
           ]
        }
    ],
}
