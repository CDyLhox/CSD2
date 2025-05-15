let audio;

const motifArray = [
	new Audio('assets/music/motifs/flute/01_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/02_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/03_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/04_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/05_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/06_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/07_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/08_motifs_flute.wav'),
	new Audio('assets/music/motifs/flute/09_motifs_flute.wav'),
];
function newMotif() {
	console.log('next motif');
	audio = motifArray[Math.floor(Math.random() * motifArray.length)];
	const sourceNode = audioCtxt.createMediaElementSource(audio);
	sourceNode.connect(genAnalyser);
	sourceNode.connect(audioCtxt.destination);
}

setInterval(() => {
	audio.play();
}, 12_000);

setInterval(newMotif, 20_000);
