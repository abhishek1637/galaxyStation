const fs = require('fs');
const path = require('path');

const packageName = process.argv[2];
if (!packageName) {
  console.error('Please provide a package name');
  process.exit(1);
}

const packagePath = path.join(__dirname, '..', 'BFF', 'CDK', packageName);
if (fs.existsSync(packagePath)) {
  console.error(`Package ${packageName} already exists`);
  process.exit(1);
}

fs.mkdirSync(packagePath, { recursive: true });

const packageJson = {
  "name": packageName,
  "version": "1.0.0",
  "main": "index.ts",
  "scripts": {
    "deploy": "cdk deploy",
    "synth": "cdk synth"
  },
  "dependencies": {
    "@aws-cdk/core": "^2.0.0",
    "@aws-cdk/aws-lambda": "^2.0.0",
    "@aws-cdk/aws-apigateway": "^2.0.0"
  }
};

fs.writeFileSync(
  path.join(packagePath, 'package.json'),
  JSON.stringify(packageJson, null, 2)
);

fs.writeFileSync(
  path.join(packagePath, 'index.ts'),
  `import * as cdk from '@aws-cdk/core';\n\nexport class ${packageName}Stack extends cdk.Stack {\n  constructor(scope: cdk.Construct, id: string, props?: cdk.StackProps) {\n    super(scope, id, props);\n    // CDK Resources here\n  }\n}`
);

console.log(`CDK package ${packageName} created successfully!`);