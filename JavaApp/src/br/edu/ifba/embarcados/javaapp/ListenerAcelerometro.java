package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class ListenerAcelerometro implements IListenerAcelerometro{

	@Override
	public void notificarMovimento(int x, int y, int z) {
		// TODO Auto-generated method stub
		System.out.println("X =" + x );
		System.out.println("Y=" + y);
		System.out.println("Z =" + z );
		
	}

	@Override
	public void notificarVibracao() {
		// TODO Auto-generated method stub
		
	}

}
