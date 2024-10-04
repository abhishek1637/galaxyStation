const fs = require('fs');
const path = require('path');

const packageName = process.argv[2];
if (!packageName) {
  console.error('Please provide a package name');
  process.exit(1);
}

const packagePath = path.join(__dirname, '..', 'BFF', 'packages', packageName);
if (fs.existsSync(packagePath)) {
  console.error(`Package ${packageName} already exists`);
  process.exit(1);
}

fs.mkdirSync(packagePath, { recursive: true });

const packageJson = {
  "name": packageName,
  "version": "1.0.0",
  "main": "index.js",
  "scripts": {
    "start": "node index.js"
  }
};

fs.writeFileSync(
  path.join(packagePath, 'package.json'),
  JSON.stringify(packageJson, null, 2)
);

fs.writeFileSync(
  path.join(packagePath, 'index.js'),
  `console.log('Welcome to ${packageName}!');`
);

console.log(`BFF package ${packageName} created successfully!`);