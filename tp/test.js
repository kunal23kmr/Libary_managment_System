// Prompt for user input
const userInput = prompt("Enter an integer:");

// Convert input to integer
const inputNumber = parseInt(userInput);

// Check if the input is a valid integer
if (isNaN(inputNumber)) {
  console.log("Invalid input. Please enter a valid integer.");
} else {
  // Convert the integer to binary representation
  const binaryString = inputNumber.toString(2);
  console.log(`Binary representation of ${inputNumber} is: ${binaryString}`);
}
