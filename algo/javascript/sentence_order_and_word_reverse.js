var sentence = "sentence order and word reverse";
var result = '', tmp = '';
var index = 0;

while (true) {
    for (; sentence[index] !== ' ' && sentence[index] !== void 0; index++) {
        tmp = sentence[index] + tmp;
    }

    result += tmp + (sentence[index] || '');

    tmp = '';

    if (sentence[index++] === void 0) {
        break;
    }
}

console.log(result); // ecnetnes redro dna drow esrever
