import eslint from '@eslint/js';
import tseslint from 'typescript-eslint';
import globals from 'globals';

export default tseslint.config(
    eslint.configs.recommended,
    tseslint.configs.recommended,
    {
        ignores: [
            'stubs/',
            'helpers/',
            'cmake-build-debug/',
            '*.config.js',
            '*.config.mjs',
        ],
    },
    {
        languageOptions: {
            ecmaVersion: 2022,
            sourceType: "commonjs",
            globals: {
                ...globals.browser,
                ...globals.node,
                myCustomGlobal: "readonly"
            }
        },
        files: [
            'camera-api-stubs.js',
            'camera-api.js',
        ],
        rules: {
            '@typescript-eslint/no-require-imports': 'off'
        }
    },
    {
        'rules': {
            'comma-dangle': [
                'error',
                'only-multiline'
            ],
            'indent': [
                'error',
                4,
                {
                    'SwitchCase': 1
                }
            ],
            'linebreak-style': [
                'error',
                'unix'
            ],
            'quotes': [
                'error',
                'single',
                {
                    avoidEscape: true
                }
            ],
            'semi': [
                'error',
                'always'
            ],
            'no-unused-vars': 'off',
            '@typescript-eslint/no-unused-vars': 'off',
            '@typescript-eslint/no-empty-interface': 'off',
            '@typescript-eslint/no-inferrable-types': [
                'error',
                {
                    ignoreParameters: true,
                    ignoreProperties: true
                },
            ]
        },
    }
);
