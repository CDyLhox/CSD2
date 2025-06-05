let audio;
let guitarLeftAudio;
let guitarRightAudio;
let pianoAudio;
let drumAudio;
let electricGuitarAudio;
let electricGuitarAudio2;

const motifContainer = document.createElement('div');
motifContainer.className = 'motifContainer';

const notationWrapper = document.createElement('div');
notationWrapper.id = 'notationWrapper';

const notation = document.createElement('img');

notationWrapper.append(notation);
motifContainer.append(notationWrapper);

const volumeWrapper = document.createElement('div');
const volumeSlider = document.createElement('input');
volumeSlider.type = 'range';
volumeSlider.min = 0;
volumeSlider.max = 1;
volumeSlider.value = 0.5;
volumeSlider.step = 0.05;

const guitarVolumeSlider = document.createElement('input');
guitarVolumeSlider.type = 'range';
guitarVolumeSlider.min = 0;
guitarVolumeSlider.max = 1;
guitarVolumeSlider.value = 0.5;
guitarVolumeSlider.step = 0.05;

volumeWrapper.append(volumeSlider);
volumeWrapper.append(guitarVolumeSlider);
motifContainer.append(volumeWrapper);

const motifArray = [];
const motifNotationArray = [];

const guitarLeftMotifArray = [];
const guitarRightMotifArray = [];
const electricGuitarArray = [];

const pianoMotifArray = [];
const drumMotifArray = [];

Promise.all([
	fetch('motifs.json').then(res => res.json()),
	fetch('guitarImprov.json').then(res => res.json()),
	fetch('pianoMotifs.json').then(res => res.json()),
	fetch('drumMotifs.json').then(res => res.json()),
]).then(([motifData, guitarData, pianoData, drumData]) => {
	const {fluteMotifs} = motifData;
	const {drumPath} = drumData;
	const {left} = guitarData;
	const {right} = guitarData;
	const {eg} = guitarData;
	const {pianoMotifPath} = pianoData;

	for (const motif of fluteMotifs) {
		motifArray.push(motif.path);
		motifNotationArray.push(motif.notation);
	}

	for (const lefty of left) {
		guitarLeftMotifArray.push(lefty);
	}

	for (const righty of right) {
		guitarRightMotifArray.push(righty);
	}

	for (const drum of drumPath) {
		drumMotifArray.push(drum);
	}

	for (const electricGuitar of eg) {
		electricGuitarArray.push(electricGuitar);
	}

	for (const pianoMotif of pianoMotifPath) {
		pianoMotifArray.push(pianoMotif);
	}

	// Now it's safe to start
	newMotif();
	setInterval(newMotif, 6000);
	setInterval(playpianoMotif, 7000);
	setInterval(playMusic, 40_000);// TODO: ADD LOGIC
}).catch(error => console.error('Fetch error:', error));

// ___________ FLUTE MOTIFS ___________
function newMotif() {
	console.log('next motif');
	const newMotif = Math.floor(Math.random() * motifArray.length);
	audio = new Audio(motifArray[newMotif]);

	const sourceNode = audioCtxt.createMediaElementSource(audio);

	sourceNode.connect(genAnalyser);
	sourceNode.connect(gainNode);
	audio.volume = 0.1;
	audio.play();

	notation.src = motifNotationArray[newMotif];
}

// ___________ GUITAR MOTIS ___________
function newGuitarMotif() {
	/*
	GuitarLeftAudio = new Audio(guitarLeftMotifArray[Math.floor(Math.random() * guitarLeftMotifArray.length)]);
	const sourceLeftNode = audioCtxt.createMediaElementSource(guitarLeftAudio);

	// Connect to gainNode
	sourceLeftNode.connect(gainNode);
	guitarLeftAudio.volume = guitarVolumeSlider.value;
	guitarLeftAudio.play();

	guitarRightAudio = new Audio(guitarRightMotifArray[Math.floor(Math.random() * guitarRightMotifArray.length)]);
	const sourceRightNode = audioCtxt.createMediaElementSource(guitarRightAudio);

	// Connect to gainNode
	sourceRightNode.connect(gainNode);
	guitarRightAudio.volume = guitarVolumeSlider.value;
	guitarRightAudio.play();

	console.log('guitarMotifs'); */ // THE GUITARS
}

// ___________ NOISE MUSIC ___________
const noiseTrack = new Audio('/assets/music/noise/noiseTracks/meanNoise.1.wav');
const sourceNoiseNode = audioCtxt.createMediaElementSource(noiseTrack);
function playNoiseMusic() {
	console.log('noisetrack is ' + noiseTrack.duration);
	sourceNoiseNode.connect(gainNode);
	noiseTrack.volume = 1 - guitarVolumeSlider.value;

	noiseTrack.play();
	console.log('playNoiseMusic: ' + noiseTrack.currentTime);
	noiseTrack.currentTime = (Math.random() * noiseTrack.duration);
}

function playpianoMotif() {
	console.log('piano should play');
	pianoAudio = new Audio(pianoMotifArray[Math.floor(Math.random() * pianoMotifArray.length)]);

	const sourcePianoNode = audioCtxt.createMediaElementSource(pianoAudio);

	sourcePianoNode.connect(gainNode);
	pianoAudio.volume = 0.6; // TODO: add slider
	pianoAudio.play().then(() => {
		console.log('Piano audio is playing!');
	})
		.catch(error => {
			console.error('Piano play error:', error);
		});
}

//
//
//
//
// MUSIC REAL MUSIC

function playMusic() {
	drumAudio = null; // Track currently playing drum audio
	if (drumAudio && !drumAudio.ended) {
		console.log('Drum is still playing, wait for it to finish.');
		return; // Don't start a new one
	}

	console.log('Starting new drum motif');
	drumAudio = new Audio(drumMotifArray[Math.floor(Math.random() * drumMotifArray.length)]);

	const sourceDrumNode = audioCtxt.createMediaElementSource(drumAudio);
	sourceDrumNode.connect(gainNode);
	drumAudio.volume = 0.6;

	drumAudio.play()
		.then(() => {
			console.log('Drum is now playing!');
		})
		.catch(error => {
			console.error('Drum play error:', error);
		});

	drumAudio.addEventListener('ended', () => {
		console.log('Drum finished.');
	});
let guitarRandom = Math.floor(Math.random() * electricGuitarArray.length);
    console.log("guitarlength ", guitarRandom)
	electricGuitarAudio = new Audio(electricGuitarArray[guitarRandom]);
    electricGuitarAudio2 = new Audio(electricGuitarArray[guitarRandom-2]);

	const sourceEGNode = audioCtxt.createMediaElementSource(electricGuitarAudio);
	const sourceEGCopyNode = audioCtxt.createMediaElementSource(electricGuitarAudio2);
    sourceEGCopyNode.connect(gainNode); //TODO: REMOVE DUPLICATE
	sourceEGNode.connect(gainNode);
	electricGuitarAudio.volume = guitarVolumeSlider.value;
    electricGuitarAudio2.volume = guitarVolumeSlider.value;
	electricGuitarAudio.play().then(() => {
		console.log('GUITAR IS THE FUCK is now playing!');
	})
		.catch(error => {
			console.error('guitar play error:', error);
		});
    electricGuitarAudio2.play();
}/* SetInterval(() => {;

	audio.play();
}, 12_000); */

var gainNode = audioCtxt.createGain();
gainNode.gain.value = volumeSlider.value; // 10 %
gainNode.connect(audioCtxt.destination);

volumeSlider.addEventListener('input', () => {
	gainNode.gain.value = volumeSlider.value;
});
guitarVolumeSlider.addEventListener('input', () => {
	guitarRightAudio.volume = guitarVolumeSlider.value;
	guitarLeftAudio.volume = guitarVolumeSlider.value;
    electricGuitarAudio2.volume = guitarVolumeSlider.value;
    electricGuitarAudio.volume = guitarVolumeSlider.value;
	noiseTrack.volume = 1 - guitarVolumeSlider.value;
});
setInterval(newGuitarMotif, 15_000);
setInterval(playNoiseMusic, 8000);

document.body.addEventListener('click', () => {
	audioCtxt.resume();
});

document.body.append(motifContainer);
