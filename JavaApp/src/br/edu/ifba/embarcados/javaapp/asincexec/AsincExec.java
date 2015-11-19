package br.edu.ifba.embarcados.javaapp.asincexec;

import java.util.ArrayList;
import java.util.List;

import br.edu.ifba.embarcados.javaapp.conector.FabricaConectores;
import br.edu.ifba.embarcados.javaapp.conector.IComunicacaoSensores;

public class AsincExec implements Runnable {

	private String porta;
	private boolean continuar; 
	
	private List<IListenerAcelerometro> listeners;
	
	public AsincExec(String porta){
		this.porta = porta;
		listeners =
			new ArrayList<IListenerAcelerometro>();
	}
	
	public void addListener(IListenerAcelerometro listener){
		listeners.add(listener);
	}
	
	public void setContinuar(boolean continuar){
		this.continuar = continuar;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		IComunicacaoSensores  conector = FabricaConectores.getConector();
		
		if (conector.iniciar(porta)==0){//coloca a porta que identificou no arduino
			continuar = true;
			while (continuar){
				conector.ler();
				
				
				notificar(conector.getAltitude(), conector.getQueda());
						
				
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			conector.finalizar();
		}
		
	}
	
	private void notificar(float altitude, int queda){
		//notificar todos de vez
		for (IListenerAcelerometro listener: listeners) {
			listener.notificarAltitude(altitude);
			listener.notificarQueda(queda);			
		}
		
	}

}
