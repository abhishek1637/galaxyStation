const fs = require('fs');
const path = require('path');

const packageName = process.argv[2];
if (!packageName) {
  console.error('Please provide a package name');
  process.exit(1);
}

const packagePath = path.join(__dirname, '..', 'UI', 'packages', packageName);
if (fs.existsSync(packagePath)) {
  console.error(`Package ${packageName} already exists`);
  process.exit(1);
}

fs.mkdirSync(packagePath, { recursive: true });

const packageJson = {
  "name": packageName,
  "version": "1.0.0",
  "main": "index.tsx",
  "scripts": {
    "start": "webpack serve --config ../../webpack.config.js"
  }
};

fs.writeFileSync(
  path.join(packagePath, 'package.json'),
  JSON.stringify(packageJson, null, 2)
);

fs.writeFileSync(
  path.join(packagePath, 'index.tsx'),
  `import React from 'react';\nimport ReactDOM from 'react-dom';\nconst App = () => <div>Welcome to ${packageName}!</div>;\nReactDOM.render(<App />, document.getElementById('root'));`
);

console.log(`UI package ${packageName} created successfully!`);