module.exports = {
    'env': {
        'node': true,
        'browser': true,
        'es2021': true
    },
    'extends': [
        'eslint:recommended',
        'plugin:@typescript-eslint/recommended'
    ],
    'parser': '@typescript-eslint/parser',
    'parserOptions': {
        'ecmaVersion': 'latest',
        'sourceType': 'module'
    },
    'plugins': [
        '@typescript-eslint'
    ],
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
    'overrides': [
        {
            'files': [
                './camera-api.js',
                './camera-api-stubs.js',
                './helpers/**'
            ],
            'rules': {
                '@typescript-eslint/no-var-requires': 'off'
            }
        }
    ],
};
