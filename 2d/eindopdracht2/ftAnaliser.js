
const audioCtxt = new (globalThis.AudioContext || globalThis.webkitAudioContext)();

const ftCanvas = document.createElement('canvas');
ftCanvas.id = 'canvas';
const canvasContext = ftCanvas.getContext('2d');
const WIDTH = ftCanvas.width = 500;
const HEIGHT = ftCanvas.height = 150;

document.body.append(ftCanvas);
let logData = '';

const genAnalyser = audioCtxt.createAnalyser();
const usrAnalyser = audioCtxt.createAnalyser();

const nyquist = audioCtxt.sampleRate / 2;

genAnalyser.fftSize = 2048;
usrAnalyser.fftSize = 1024;

genAnalyser.smoothingTimeConstant = 0.8;
usrAnalyser.smoothingTimeConstant = 0.8;

const bufferSize = genAnalyser.frequencyBinCount;

const genDataArray = new Uint8Array(bufferSize);
const usrDataArray = new Uint8Array(bufferSize);

let pitchInterval;
const log = document.createElement('p');
log.id = 'log';
document.body.appendChild(log);
const negativeVideoContainer = document.querySelector('#negativeVideoContainer');

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

// ____________ audioCtx _________

if (audioCtxt.state) {
	log.textContent = 'click anywhere to begin';
	onclick = e => {
		onclick = null;
		begin();
	};
} else {
	begin();
}

function begin() {
	const localAudio = document.createElement('audio');
	localAudio.id = 'localAudio';
	document.body.append(localAudio);
	getLocalStream();
	if (audioCtxt.state === 'suspended') {
	audioCtxt.resume();
}

	draw();
}

// PitchInterval = setInterval(newPitch, 1000);

// ____________ compare audios ___________

function draw() {
	requestAnimationFrame(draw);
	if (audioCtxt.state === 'suspended') {
	audioCtxt.resume();
}


	genAnalyser.getByteFrequencyData(genDataArray);
	usrAnalyser.getByteFrequencyData(usrDataArray);

	canvasContext.fillStyle = 'rgb(0, 0, 0)';
	canvasContext.fillRect(0, 0, WIDTH, HEIGHT);

	let genMax_value = -Infinity;
	let genMax_index = -1;

	let usrMax_value = -Infinity;
	let usrMax_index = -1;

	let x = 0;
	for (let i = 0; i < bufferSize; i++) {
		const genBarHeight = genDataArray[i];
		const usrBarHeight = usrDataArray[i];

		if (genBarHeight > genMax_value) {
			genMax_value = genBarHeight;
			genMax_index = i;
		}

		if (usrBarHeight > usrMax_value) {
			usrMax_value = usrBarHeight;
			usrMax_index = i;
		}

		canvasContext.fillStyle = `rgb(${genBarHeight + 100}, 50, 50)`;
		canvasContext.fillRect(x, HEIGHT - genBarHeight / 2, barWidth, genBarHeight / 2);

		canvasContext.fillStyle = `rgb(50, 100, ${usrBarHeight + 150})`;
		canvasContext.fillRect(x, HEIGHT - usrBarHeight / 2, barWidth, usrBarHeight / 2);

		x += barWidth;
	}

	const genFreq = genMax_index * (nyquist / bufferSize);
	const usrFreq = usrMax_index * (nyquist / bufferSize);

	const freqDifference = Math.abs(genFreq - usrFreq);
	const maxFreq = Math.max(genFreq, usrFreq);
	const similarityPercentage = 100 - (freqDifference / maxFreq) * 100;

	const logLine = `Generated freq: ${genFreq.toFixed(2)} Hz, User freq: ${usrFreq.toFixed(2)} Hz, Similarity: ${similarityPercentage.toFixed(1)}%\n`;
	logData += logLine;
	log.textContent = logLine;

	let negativeOpacity = Number.parseFloat(negativeVideoContainer.style.opacity) || 1;

	if (similarityPercentage > 90) {
		negativeOpacity = (90 - similarityPercentage) * -0.1;
		negativeOpacity = Math.min(1, Math.max(0, negativeOpacity)); // Clamp between 0–1
	} else {
		negativeOpacity = Math.min(1, negativeOpacity + 0.05);
	}

	negativeVideoContainer.style.opacity = negativeOpacity;
}

// _________ downloadLogContent _________
function downloadLog(content) {
	const blob = new Blob([content], {type: 'text/plain'});
	const url = URL.createObjectURL(blob);
	const a = document.createElement('a');
	a.href = url;
	a.download = 'frequency_similarity_log.txt';
	document.body.append(a);
	a.click();
	a.remove();
	URL.revokeObjectURL(url);
}

function getLocalStream() {
	navigator.mediaDevices
		.getUserMedia({video: false, audio: true})
		.then(stream => {
			const source = audioCtxt.createMediaStreamSource(stream);
			source.connect(usrAnalyser);
			source.connect(audioCtxt.destination); // for hearing mic input


			globalThis.localStream = stream; // A
			globalThis.localAudio.srcObject = stream; // B
			globalThis.localAudio.autoplay = true; // C
		})
		.catch(error => {
			console.error(`you got an error: ${error}`);
		});
}
