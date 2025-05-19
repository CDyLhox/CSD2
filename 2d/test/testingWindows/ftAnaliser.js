
document.body.append(ftCanvas);

const audioCtxt = new (globalThis.AudioContext || globalThis.webkitAudioContext)();
const ftCanvas = document.createElement('canvas');
ftCanvas.id = 'canvas';
const canvasContext = ftCanvas.getContext('2d');
const WIDTH = ftCanvas.width = 500;
const HEIGHT = ftCanvas.height = 150;

let logData = '';

const genAnalyser = audioCtxt.createAnalyser();
const usrAnalyser = audioCtxt.createAnalyser();

const nyquist = audioCtxt.sampleRate / 2;

genAnalyser.fftSize = 32_768;
usrAnalyser.fftSize = 32_768;

const bufferSize = genAnalyser.frequencyBinCount;

const genDataArray = new Uint8Array(bufferSize);
const usrDataArray = new Uint8Array(bufferSize);

let pitchInterval;
const log = document.getElementById('log');
const negativeVideoContainer = document.getElementById('negativeVideoContainer');


// _________ DRAW SPECTRUM _________
canvasContext.fillStyle = 'rgb(0, 0, 0)';
canvasContext.fillRect(0, 0, WIDTH, HEIGHT);

const barWidth = (WIDTH / bufferSize) * 2.5;
let genMax_value = -Infinity;
let genMax_index = -1;

let usrMax_value = -Infinity;
let usrMax_index = -1;

let x = 0;
for (let i = 0; i < bufferSize; i++) {
	const genBarHeight = genDataArray[i];
	if (genBarHeight > genMax_value) {
		genMax_value = genBarHeight;
		genMax_index = i;
	}

	const usrBarHeight = usrDataArray[i];
	if (usrBarHeight > usrMax_value) {
		usrMax_value = usrBarHeight;
		usrMax_index = i;
	}

	canvasContext.fillStyle = 'rgb(' + (genBarHeight + 100) + ',50,50)';
	canvasContext.fillRect(x, HEIGHT - genBarHeight / 2, barWidth, genBarHeight / 2);

	canvasContext.fillStyle = 'rgb(50,100,' + (genBarHeight + 150) + ')';
	canvasContext.fillRect(x, HEIGHT - usrBarHeight / 2, barWidth, usrBarHeight / 2);

	x += barWidth;
}

const genFreq = genMax_index * (nyquist / bufferSize);
const usrFreq = usrMax_index * (nyquist / bufferSize);

const freqDifference = Math.abs(genFreq - usrFreq);
const maxFreq = Math.max(genFreq, usrFreq);
const similarityPercentage = 100 - (freqDifference / maxFreq) * 100;

// _________ LOG THE LOUD __________
const logLine = `Generated freq: ${genFreq.toFixed(2)} Hz, User freq: ${usrFreq.toFixed(2)} Hz, Similarity: ${similarityPercentage.toFixed(1)}%\n`;
logData += logLine;

log.textContent = logLine;

// Check if the percentage is higher than 90, decrease negativevidopacity

if (similarityPercentage > 90) {
	var negativeOpacity = (90 - similarityPercentage) * -0.1;
	negativeVideoContainer.style.opacity = negativeOpacity;
} else if (similarityPercentage < 90 && negativeOpacity < 1) {
	negativeOpacity += 0.05;
	negativeVideoContainer.style.opacity = negativeOpacity;
} else {
	negativeVideoContainer.style.opacity = 1;
}




