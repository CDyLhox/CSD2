const canvasContext = canvas.getContext('2d');
const WIDTH = canvas.width = 500;
const HEIGHT = canvas.height = 150;

const audioCtxt = new (globalThis.AudioContext || globalThis.webkitAudioContext)();
const analyser = audioCtxt.createAnalyser();

const nyquist = audioCtxt.sampleRate / 2;

analyser.fftSize = 32_768;

const bufferSize = analyser.frequencyBinCount;
const dataArray = new Uint8Array(bufferSize);

// Osc
//const osc = audioCtxt.createOscillator();
//osc.frequency.value = 400;
//osc.connect(analyser);
//stream.connect(audioCtxt.destination);

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
	//osc.start(0);
	draw();
	getLocalStream();
}

function draw() {
	requestAnimationFrame(draw);

	analyser.getByteFrequencyData(dataArray);

	canvasContext.fillStyle = 'rgb(0, 0, 0)';
	canvasContext.fillRect(0, 0, WIDTH, HEIGHT);

	const barWidth = (WIDTH / bufferSize) * 2.5;
	let max_value = -Infinity;
	let max_index = -1;
	let x = 0;
	for (let i = 0; i < bufferSize; i++) {
		const barHeight = dataArray[i];
		if (barHeight > max_value) {
			max_value = barHeight;
			max_index = i;
		}

		canvasContext.fillStyle = 'rgb(' + (barHeight + 100) + ',50,50)';
		canvasContext.fillRect(x, HEIGHT - barHeight / 2, barWidth, barHeight / 2);
		x += barWidth;
	}

	log.textContent = `loudest freq: ${max_index * (nyquist / bufferSize)}
real value: ${range.value}`;
}

function getLocalStream() {
	navigator.mediaDevices
		.getUserMedia({video: false, audio: true})
		.then(stream => {
			const source = audioCtxt.createMediaStreamSource(stream);
			source.connect(analyser);

			globalThis.localStream = stream; // A
			globalThis.localAudio.srcObject = stream; // B
			globalThis.localAudio.autoplay = true; // C
		})
		.catch(error => {
			console.error(`you got an error: ${error}`);
		});
}
