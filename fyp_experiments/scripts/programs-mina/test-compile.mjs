// Auto-generated test script
import { circuit as circuit0 } from './arithmetic_circuit_2867825.js';
import { circuit as circuit1 } from './arithmetic_circuit_1419610.js';
import { circuit as circuit2 } from './arithmetic_circuit_5614226.js';
import { circuit as circuit3 } from './arithmetic_circuit_5108603.js';
import { circuit as circuit4 } from './arithmetic_circuit_4744854.js';
import { circuit as circuit5 } from './boolean_circuit_3341057.js';
import { circuit as circuit6 } from './boolean_circuit_2719583.js';
import { circuit as circuit7 } from './boolean_circuit_2458591.js';
import { circuit as circuit8 } from './boolean_circuit_8078673.js';
import { circuit as circuit9 } from './boolean_circuit_1533224.js';

let success = 0;
let failed = 0;

async function main() {
  console.log('Testing o1js circuit compilation...');
  console.log();

  try {
    console.log('Compiling arithmetic_circuit_2867825...');
    await circuit0.compile();
    console.log('✓ arithmetic_circuit_2867825 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ arithmetic_circuit_2867825 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling arithmetic_circuit_1419610...');
    await circuit1.compile();
    console.log('✓ arithmetic_circuit_1419610 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ arithmetic_circuit_1419610 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling arithmetic_circuit_5614226...');
    await circuit2.compile();
    console.log('✓ arithmetic_circuit_5614226 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ arithmetic_circuit_5614226 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling arithmetic_circuit_5108603...');
    await circuit3.compile();
    console.log('✓ arithmetic_circuit_5108603 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ arithmetic_circuit_5108603 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling arithmetic_circuit_4744854...');
    await circuit4.compile();
    console.log('✓ arithmetic_circuit_4744854 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ arithmetic_circuit_4744854 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling boolean_circuit_3341057...');
    await circuit5.compile();
    console.log('✓ boolean_circuit_3341057 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ boolean_circuit_3341057 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling boolean_circuit_2719583...');
    await circuit6.compile();
    console.log('✓ boolean_circuit_2719583 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ boolean_circuit_2719583 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling boolean_circuit_2458591...');
    await circuit7.compile();
    console.log('✓ boolean_circuit_2458591 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ boolean_circuit_2458591 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling boolean_circuit_8078673...');
    await circuit8.compile();
    console.log('✓ boolean_circuit_8078673 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ boolean_circuit_8078673 failed:', e.message.slice(0, 100));
    failed++;
  }
  try {
    console.log('Compiling boolean_circuit_1533224...');
    await circuit9.compile();
    console.log('✓ boolean_circuit_1533224 compiled successfully');
    success++;
  } catch (e) {
    console.log('✗ boolean_circuit_1533224 failed:', e.message.slice(0, 100));
    failed++;
  }
  console.log();
  console.log(`Compilation summary: ${success}/${success + failed} circuits compiled successfully`);
  process.exit(failed > 0 ? 1 : 0);
}

main();
