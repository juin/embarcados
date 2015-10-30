package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.AsincExec;


public class Executor {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		AsincExec asinc = 
				new AsincExec("/dev/ttyACM0");
		//vamos colocar ao menos um escutador
		//tem que colocar o listener dentro do asinc para ele usar
		ListenerAcelerometro listener = 
				new ListenerAcelerometro();
		asinc.addListener(listener);
		//passar o asinc como se fosse uma thread
		
		Thread t = new Thread(asinc);
		//nesse ponto que a thread começa a rodar em paralelo
		t.start();
		//depois dos 10 segundos que usar a thread vai para-la
		//Essa thread sleep diz respeito ao main a outra thread vai correr normalmente
		for (int i = 0; i < 10; i++) {
			Thread.sleep(1000);
		}
		asinc.setContinuar(false);
		//ter certeza q a thread vai parar
		t.join();

	}

}
