const fs = require('fs');
const path = require('path');
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the file name: ', (fileName) => {
  rl.question('Enter the topic related to (e.g., Array, Tree, etc.): ', (problemType) => {
    rl.question('Enter the theory description in a sentence: ', (problemDescription) => {

      const problemPath = path.join(__dirname, '..', 'DSA/Theory', problemType);
      if (!fs.existsSync(problemPath)) {
        fs.mkdirSync(problemPath, { recursive: true });
      }

      const filePath = path.join(problemPath, `${fileName}.cpp`);
      if (fs.existsSync(filePath)) {
        console.error(`File ${fileName}.cpp already exists in ${problemType}`);
        process.exit(1);
      }

      const fileContent = `/**\n * ${problemDescription}\n */\n\n#include <iostream>\nusing namespace std;\n`;
      fs.writeFileSync(filePath, fileContent);

      console.log(`DSA problem file ${fileName}.cpp created successfully under ${problemType}!`);

      rl.close();
    });
  });
});