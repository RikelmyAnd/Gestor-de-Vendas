package src.org;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<Venda> vendas = List.of(
                new Venda("Camiseta Infantil", "Roupas", 10, 29.90, "Ana"),
                new Venda("Short Infantil", "Roupas", 5, 34.90, "Bruno"),
                new Venda("Tênis Infantil", "Calçados", 3, 119.90, "Ana"),
                new Venda("Sandália Infantil", "Calçados", 4, 79.90, "Carlos"),
                new Venda("Boneca", "Brinquedos", 7, 49.90, "Bruno"),
                new Venda("Carrinho", "Brinquedos", 6, 39.90, "Ana"),
                new Venda("Mochila Escolar", "Acessórios", 2, 89.90, "Carlos"),
                new Venda("Boné Infantil", "Acessórios", 8, 24.90, "Ana"),
                new Venda("Vestido Infantil", "Roupas", 4, 69.90, "Bruno"),
                new Venda("Chinelo Infantil", "Calçados", 9, 29.90, "Carlos"));

        System.out.println("Vendas de Roupas:");
        filtrarRoupasFuncional(vendas).forEach(System.out::println);

        System.out.println("\nFaturamento Total: " + calcularFaturamentoFuncional(vendas));
            
        System.out.println("\nVendas Acima de R$200:");
        vendasAcimaDe200Funcional(vendas).forEach(System.out::println);

        System.out.println("\nNomes dos Produtos Vendidos:");
        nomesProdutosFuncional(vendas).forEach(System.out::println);   

        System.out.println("\nTotal por Vendedor:");
        totalPorVendedorFuncional(vendas).forEach((vendedor, total) -> System.out.println(vendedor + ": R$" + total));

        System.out.println("\nMaior Venda:");
        System.out.println(maiorVendaFuncional(vendas));

        System.out.println("\nVendas Ordenadas por Total:");
        ordenarPorTotalFuncional(vendas).forEach(System.out::println);


    }

    public static List<Venda> filtrarRoupasFuncional(List<Venda> vendas) {
        return vendas.stream()
                .filter(v -> v.getCategoria().equalsIgnoreCase("Roupas"))
                .toList();
    }

    public static double calcularFaturamentoFuncional(List<Venda> vendas) {
        return vendas.stream()
                .mapToDouble(Venda::getTotal)
                .sum();
    }

    public static List<Venda> vendasAcimaDe200Funcional(List<Venda> vendas) {
        return vendas.stream()
                .filter(v -> v.getTotal() > 200)
                .toList();
    }

    public static List<String> nomesProdutosFuncional(List<Venda> vendas) {
        return vendas.stream()
                .map(Venda::getProduto)
                .toList();
    }

    public static Map<String, Double> totalPorVendedorFuncional(List<Venda> vendas) {
        return vendas.stream()
                .collect(Collectors.groupingBy(Venda::getVendedor, Collectors.summingDouble(Venda::getTotal))); 
                
    }

    public static Venda maiorVendaFuncional(List<Venda> vendas) {
        return vendas.stream()
                .max((v1, v2) -> Double.compare(v1.getTotal(), v2.getTotal()))
                .orElse(null);
    }

    public static List<Venda> ordenarPorTotalFuncional(List<Venda> vendas) {
        return vendas.stream()
                .sorted((v1, v2) -> Double.compare(v1.getTotal(), v2.getTotal()))
                .toList();
    }

}