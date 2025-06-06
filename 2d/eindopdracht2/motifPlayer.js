let audio;
let guitarLeftAudio;
let guitarRightAudio;
let pianoAudio;
let drumAudio;
let electricGuitarAudio;
let electricGuitarAudio2;
let choirAudio, fluteImrpoAudio;
let poetryAudio;

const activeAudioFunctions = new Set();
const MAX_ACTIVE_FUNCTIONS = 5;

// Chatgpt suggestion
function runAudioFunction(name, fn) {
	if (activeAudioFunctions.size >= MAX_ACTIVE_FUNCTIONS) {
		console.log(`${name} skipped — too many active functions.`);
		return;
	}

	if (activeAudioFunctions.has(name)) {
		console.log(`${name} already active.`);
		return;
	}

	activeAudioFunctions.add(name);
	fn(() => {
		activeAudioFunctions.delete(name);
		console.log(`${name} finished and removed.`);
	});
}

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
const fluteImproMotifArray = [];

const guitarLeftMotifArray = [];
const guitarRightMotifArray = [];
const electricGuitarArray = [];

const pianoMotifArray = [];
const drumMotifArray = [];
const choirMotifArray = [];

const poetryMotifArray = [];

Promise.all([
	fetch('motifs.json').then(res => res.json()),
	fetch('guitarImprov.json').then(res => res.json()),
	fetch('pianoMotifs.json').then(res => res.json()),
	fetch('drumMotifs.json').then(res => res.json()),
    fetch('choir.json').then(res => res.json()),
    fetch('poetry.json').then(res => res.json()),
]).then(([motifData, guitarData, pianoData, drumData, choirData, poetryData]) => {
	const {fluteMotifs} = motifData;
    const {fluteImpro} = motifData;
	const {drumPath} = drumData;
	const {left} = guitarData;
	const {right} = guitarData;
	const {eg} = guitarData;
	const {pianoMotifPath} = pianoData;
    const {choirPath} = choirData;
    const {poetryPath} = poetryData 

	for (const motif of fluteMotifs) {
		motifArray.push(motif.path);
		motifNotationArray.push(motif.notation);
	}

    for (const imrpo of fluteImpro){
        fluteImproMotifArray.push(imrpo)
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
    for (const choir of choirPath){
        choirMotifArray.push(choir);
    }
    for (const poetryPaths of poetryPath){
        poetryMotifArray.push(poetryPaths);
    }

    // starting audio playback after the json files finished loading
    runAudioFunction('flute', done => newMotif(done));
    playNoiseMusic();
    
    
}).catch(error => console.error('Fetch error:', error));

// ___________ FLUTE MOTIFS ___________
function newMotif(done) {
	console.log('next motif');
	const newMotif = Math.floor(Math.random() * motifArray.length);
	audio = new Audio(motifArray[newMotif]);

	const sourceNode = audioCtxt.createMediaElementSource(audio);

	sourceNode.connect(gainNode);
	audio.volume = 0.1;
	audio.play();

	notation.src = motifNotationArray[newMotif];

	audio.addEventListener('ended', () => {
		done();
	});
}

// ___________ GUITAR MOTIS ___________
function newGuitarMotif(done) {
	
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

    const checkEnded = () => {
		if (guitarRightAudio.ended && guitarLeftAudio.ended) {
			done();
		}
	};

	guitarRightAudio.onended = checkEnded;
	guitarLeftAudio.onended = checkEnded;

	console.log('guitarMotifs');  // THE GUITARS
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

function playpianoMotif(done) {
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
	pianoAudio.addEventListener('ended', done);
}

//
//
//
//
// MUSIC REAL MUSIC

function playMusic(done) { //TODO: add flute 
	console.log('Starting drum & electric guitar');
	const drumPath = drumMotifArray[Math.floor(Math.random() * drumMotifArray.length)];
	drumAudio = new Audio(drumPath);
	const sourceDrumNode = audioCtxt.createMediaElementSource(drumAudio);
	sourceDrumNode.connect(gainNode);
	drumAudio.volume = 0.6;

	const guitarIndex = Math.floor(Math.random() * electricGuitarArray.length);
	electricGuitarAudio = new Audio(electricGuitarArray[guitarIndex]);
	electricGuitarAudio2 = new Audio(electricGuitarArray[Math.max(0, guitarIndex - 2)]);

	const sourceEGNode = audioCtxt.createMediaElementSource(electricGuitarAudio);
	const sourceEG2Node = audioCtxt.createMediaElementSource(electricGuitarAudio2);
	sourceEGNode.connect(gainNode);
	sourceEG2Node.connect(gainNode);

	fluteImrpoAudio = new Audio(fluteImproMotifArray[Math.floor(Math.random()*fluteImproMotifArray.length)]);
    const sourceImrpoNode = audioCtxt.createMediaElementSource(fluteImrpoAudio);
    sourceImrpoNode.connect(gainNode);
    fluteImrpoAudio.volume = 0.3;
    fluteImrpoAudio.play();
	electricGuitarAudio.volume =0.5 //TODO:: VOLUME
	electricGuitarAudio2.volume =0.5 

	electricGuitarAudio.play();
	electricGuitarAudio2.play();
	drumAudio.play();

	// When ALL are done:
	const checkEnded = () => {
		if (drumAudio.ended && electricGuitarAudio.ended && electricGuitarAudio2.ended) {
			done();
		}
	};

	drumAudio.addEventListener('ended', checkEnded);
	electricGuitarAudio.addEventListener('ended', checkEnded);
	electricGuitarAudio2.addEventListener('ended', checkEnded);
}

function playChoirMusic(done){

    console.log("PREASE THE SOUNDS OF THE HUMAN VOICE");
    const choirPath = choirMotifArray[Math.floor(Math.random()*choirMotifArray.length)];
    choirAudio = new Audio(choirPath);
    const sourceChoirNode = audioCtxt.createMediaElementSource(choirAudio);
    sourceChoirNode.connect(gainNode);
    choirAudio.volume = 0.4;

    choirAudio.play();
choirAudio.addEventListener('ended', done);

}

let poetryIsPlaying = false;
function playPoetry() {
	if (poetryIsPlaying) {
		console.log("Poetry already playing skipping. yeuh yueh ");
		return;
	}
    console.log("playpoetry, boy waht you talking about");
	poetryIsPlaying = true;

	const poetryPath = poetryMotifArray[Math.floor(Math.random() * poetryMotifArray.length)];
	poetryAudio = new Audio(poetryPath);
	const sourcePoetryNode = audioCtxt.createMediaElementSource(poetryAudio);
	sourcePoetryNode.connect(gainNode);

	poetryAudio.play();
	poetryAudio.addEventListener('ended', () => {
		poetryIsPlaying = false;
		console.log("Poetry finished.");
	});
}
/* SetInterval(() => {;

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
setInterval(playNoiseMusic, 17_000);
setInterval(playPoetry,83000);
setInterval(() => runAudioFunction('guitar', done => newGuitarMotif(done)), 11000);
setInterval(() => runAudioFunction('music', done => playMusic(done)), 41000);
setInterval(() => runAudioFunction('pianomusic', done => playpianoMotif(done)), 7000);
setInterval(() => runAudioFunction('choir', done => playChoirMusic(done)), 13000);
setInterval(() => runAudioFunction('flute', done => newMotif(done)), 6000);

document.body.addEventListener('click', () => {
	audioCtxt.resume();
});

document.body.append(motifContainer);
