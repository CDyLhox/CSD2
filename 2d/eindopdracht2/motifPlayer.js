let audio;
let guitarLeftAudio;
let guitarRightAudio;

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

Promise.all([
	fetch('motifs.json').then(res => res.json()),
	fetch('guitarImprov.json').then(res => res.json()),
]).then(([motifData, guitarData]) => {
	const {fluteMotifs} = motifData;
	const {left} = guitarData;
	const {right} = guitarData;

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
	// Now it's safe to start
	newMotif();
	setInterval(newMotif, 6000);
}).catch(error => console.error('Fetch error:', error));







//___________ FLUTE MOTIFS ___________
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






//___________ GUITAR MOTIS ___________ 
	function newGuitarMotif() {
    guitarLeftAudio = new Audio(guitarLeftMotifArray[Math.floor(Math.random() * guitarLeftMotifArray.length)]);
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


    console.log("guitarMotifs");
}







// ___________ NOISE MUSIC ___________
	let noiseTrack = new Audio("/assets/music/noise/noiseTracks/meanNoise.1.wav");
		const sourceNoiseNode = audioCtxt.createMediaElementSource(noiseTrack);
	function playNoiseMusic(){
		console.log("noisetrack is " + noiseTrack.duration);
		sourceNoiseNode.connect(gainNode);
		noiseTrack.volume = 1-guitarVolumeSlider.value;
		
noiseTrack.play();
		console.log("playNoiseMusic: " +  noiseTrack.currentTime);
noiseTrack.currentTime = (Math.random() * noiseTrack.duration);

	}







/* SetInterval(() => {
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
    noiseTrack.volume = 1-guitarVolumeSlider.value;
});
setInterval(newGuitarMotif, 15000);
setInterval(playNoiseMusic, 8000);

document.body.addEventListener('click', () => {
  audioCtxt.resume();
});


document.body.append(motifContainer);
