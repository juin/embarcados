package br.edu.ifba.embarcados.javaapp.asincexec;

import java.util.ArrayList;
import org.apache.log4j.Logger;
import java.util.List;

import br.edu.ifba.embarcados.javaapp.conector.FabricaConectores;
import br.edu.ifba.embarcados.javaapp.conector.IComunicacaoSensores;
import test.pack.Log4j;

public class AsincExec implements Runnable {
	
	private static final Logger Log = Logger.getLogger(Log4j.class);
	private String porta;
	private boolean continuar; 
	private float inicio;
	private float fim;
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
				
				//notificar(conector.getAltitude(), conector.getQueda());

				char queda = conector.getQueda();
				
				if(queda == 'N'){
					inicio = conector.getAltitude();
					Log.info("Inicio: "+ inicio);
					
				}
				
				try {
					Thread.sleep(50);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

				if(queda == 'Q'){
					fim = conector.getAltitude();
					Log.info("Queda, Altiditude Inicial: " + inicio + " Altitude Final: "+ fim);
					notificar(inicio, fim);
				}
			}
			
			conector.finalizar();
		}
		
	}
	
	private void notificar(float inicio, float fim){
		//notificar todos de vez
		for (IListenerAcelerometro listener: listeners) {
			listener.guardarLog(inicio,fim);
		}
		
	}

}
