let audio;

		const motifArray = [];

fetch('motifs.json')
	.then(response => response.json()) // Parse the json file
	.then(data => {
		const fluteMotifs = data.fluteMotifs; // extract flutemotifs from json data
		console.log(data);


		for (let i = 0; i < fluteMotifs.length; i++) {
			motifArray[i] = fluteMotifs[i].path;
		}
	},
	)

	.catch(error => console.error('error fetching json', error));

function newMotif() {
	console.log('next motif');
	audio = motifArray[Math.floor(Math.random() * motifArray.length)];
	const sourceNode = audioCtxt.createMediaElementSource(audio);
	sourceNode.connect(genAnalyser);
	sourceNode.connect(audioCtxt.destination);
	audio.play();
}

/*setInterval(() => {
	audio.play();
}, 12_000);*/

setInterval(newMotif, 20_000);
