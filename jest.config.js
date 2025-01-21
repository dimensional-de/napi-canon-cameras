module.exports = {
    verbose: true,
    roots: ["<rootDir>/tests"],
    testMatch: ["**/tests.(*).(ts|tsx|js)"],
    transform: {
        "^.+\\.(ts|tsx)$": "ts-jest",
    },
    setupFilesAfterEnv: ["jest-os-detection"],
};
