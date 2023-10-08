# shell

Tabii ki, aşağıda Minishell projesi için Türkçe bir README önerisi bulabilirsiniz:

# Minishell Projesi

Minishell projesi, 42 okulu müfredatının en zorlayıcı ve keyifli projelerinden biridir. Bu projede bir dizi test durumuyla başa çıkmak ve yazılım mimarisi, sistem çağrıları, dosya tanımlayıcıları gibi birçok konuyu öğrenmek zorunda kalırsınız. Aynı zamanda takım koordinasyonu, yönetimi ve iş bölümü gibi yeteneklerinizi de geliştirebilirsiniz.

Minishell, bash kabuğunu taklit eden bir komut satırı yorumlayıcısı (shell) oluşturmanızı gerektirir. Projenin amacı, bash'ın temel işlevselliğini içermekle birlikte, bazı temel özellikleri gerçekleştirmektir.

## Kullanım

Projeyi kullanmak oldukça basittir. İlk olarak, `make` komutunu kullanarak `minishell` yürütülebilir dosyasını oluşturmanız gerekmektedir. Ardından aşağıdaki komutla programı başlatabilirsiniz:

```bash
./minishell
```

## Özellikler ve İşlevler

Minishell, aşağıdaki temel işlevselliği içermelidir:

- Minishell sadece etkileşimli modda çalışır (betikler desteklenmez, yani yürütülebilir dosya argümanı alamaz).
- Mutlak, göreli veya çevresel PATH'den (örneğin, /bin/ls veya sadece ls gibi) basit komutları çalıştırabilirsiniz.
- Komutları, argümanlar ve seçeneklerle birlikte çalıştırabilirsiniz.
- Çalıştırılan komutların geçmişini (yukarı/aşağı ok tuşlarıyla) görüntüleyebilirsiniz.
- Boruları (`|`) ve yönlendirmeleri (`<`, `>`, `>>`) kullanabilirsiniz.
- İşaretleme yapabilirsiniz (`""` ve `''` ile özel karakterlerden kaçınmak için).
- Çevre değişkenlerini (örneğin, `$HOME`) ve dönüş kodunu (`$?`) kullanabilirsiniz.
- Sinyalleri (Ctrl-C, Ctrl-\, Ctrl-D gibi) işleyebilirsiniz.

Ayrıca, aşağıdaki yerleşik işlevleri uygulamalısınız:

- echo (sadece `-n` seçeneği)
- exit
- env (herhangi bir seçenek veya argüman olmadan)
- export (herhangi bir seçenek olmadan)
- unset (herhangi bir seçenek olmadan)
- cd
- pwd

## Proje Geliştirme

Bu projenin geliştirilmesi iki ana bölüme ayrılabilir: ayrıştırma ve yürütme.

- Ayrıştırma: Kullanıcı girdilerini işlemek ve komutları ayrıştırmak için gereklidir. Bu aşamada kullanıcı girdisi tokenlere ayrılır ve bir sözdizimi ağacı (syntax tree) veya soyut sözdizimi ağacı (AST) oluşturulur. Ayrıştırma, özel bir dil grameri kullanılarak yapılır.

- Yürütme: Oluşturulan AST veya sözdizimi ağacı temel alınarak komutların gerçekleştirilmesini sağlar. Dosya tanımlayıcılarını yönetme, süreçleri çoğaltma ve komutları yürütme gibi işlemleri içerir.

## Proje Zorlukları

Bu projenin geliştirilmesi sırasında bazı zorluklarla karşılaşabilirsiniz. Özellikle işaretleme, boru hattı işlemleri ve dosya yönlendirmeleri gibi konular karmaşık olabilir. Ayrıca, yerleşik işlevlerin doğru bir şekilde çalıştığından emin olmak için özen göstermelisiniz.

Proje geliştirme aşamasında, işbirliği yaptığınız takım üyeleriyle uyum içinde çalışmak ve işleri etkili bir şekilde dağıtmak önemlidir.

## Sonuç

Minishell projesi, zorluğuna rağmen, yazılım geliştirme ve sistem çağrıları gibi birçok konuyu öğrenmek için harika bir fırsat sunar. Ayrıca, işbirliği yapma, yönetim ve sorun giderme yeteneklerinizi geliştirmenize yardımcı olabilir.

Projeyle ilgili daha fazla ayrıntıyı kodun kendisinde bulabilirsiniz. Kod örnekleri ve daha fazla bilgi için GitHub hesabımı ziyaret edebilirsiniz: [GitHub - m4nnb3ll](https://github.com/m4nnb3ll).

Umarım bu README belgesi, Minishell projesini anlama ve başarıyla tamamlama sürecinize yardımcı olur. Başarılar dilerim!