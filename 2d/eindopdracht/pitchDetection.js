const canvasContext = canvas.getContext('2d');
const WIDTH = canvas.width = 500;
const HEIGHT = canvas.height = 150;

const audioCtxt = new (globalThis.AudioContext || globalThis.webkitAudioContext)();
const genAnalyser = audioCtxt.createAnalyser();
const usrAnalyser = audioCtxt.createAnalyser(); 

const nyquist = audioCtxt.sampleRate / 2;

genAnalyser.fftSize = 32_768;
usrAnalyser.fftSize = 32_768;

const bufferSize = genAnalyser.frequencyBinCount;

const genDataArray = new Uint8Array(bufferSize);
const usrDataArray = new Uint8Array(bufferSize) 


let pitchInterval;


// Osc
const osc = audioCtxt.createOscillator();
const frequencies = [261.63, 493.88, 329.63, 349.23];
osc.connect(genAnalyser);
osc.connect(audioCtxt.destination);


range.addEventListener('input', e => {
	osc.frequency.value = range.value;
});

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
	osc.start(0);
	draw();

	getLocalStream();
}


pitchInterval = setInterval(newPitch, 1000);
function newPitch() {
	osc.frequency.value = frequencies[Math.floor(Math.random() * frequencies.length)];

}

function draw() {
	requestAnimationFrame(draw);

	genAnalyser.getByteFrequencyData(genDataArray);
	usrAnalyser.getByteFrequencyData(usrDataArray);


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

		canvasContext.fillStyle = 'rgb(50,50,'+ (genBarHeight + 100) +')';
		canvasContext.fillRect(x, HEIGHT - usrBarHeight / 2, barWidth, usrBarHeight / 2);

		x += barWidth;
	}
	// _________ LOG THE LOUD __________

	log.textContent = `loudest freq: ${genMax_index * (nyquist / bufferSize)}
real value: ${range.value}`;
}

function getLocalStream() {
	navigator.mediaDevices
		.getUserMedia({video: false, audio: true})
		.then(stream => {
			const source = audioCtxt.createMediaStreamSource(stream);
			source.connect(usrAnalyser);

			globalThis.localStream = stream; // A
			globalThis.localAudio.srcObject = stream; // B
			globalThis.localAudio.autoplay = true; // C
		})
		.catch(error => {
			console.error(`you got an error: ${error}`);
		});
}
