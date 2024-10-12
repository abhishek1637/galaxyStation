const fs = require('fs');
const path = require('path');
const readline = require('readline');
const { exec } = require('child_process'); // Import the child_process module

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the problem name: ', (fileName) => {
  rl.question('Enter the problem related to (e.g., Array, Tree, etc.): ', (problemType) => {
    rl.question('Enter the problem description: ', (problemDescription) => {

      const problemPath = path.join(__dirname, '..', 'DSA/Problems', problemType);
      if (!fs.existsSync(problemPath)) {
        fs.mkdirSync(problemPath, { recursive: true });
      }

      const filePath = path.join(problemPath, `${fileName}.cpp`);
      if (fs.existsSync(filePath)) {
        console.error(`File ${fileName}.cpp already exists in ${problemType}`);
      } else {
        const fileContent = `/**\n * ${problemDescription}\n */\n\n#include<iostream>\nusing namespace std;\n\nint main() {\n  // Solution here\n  return 0;\n}`;
        fs.writeFileSync(filePath, fileContent);
        console.log(`DSA problem file ${fileName}.cpp created successfully under ${problemType}!`);
      }

      // Open the file in VSCode
      exec(`code -r "${filePath}"`, (err) => {
        if (err) {
          console.error('Error opening the file in VSCode:', err);
        }
      });

      rl.close();
    });
  });
});