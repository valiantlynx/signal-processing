<script>
    import { page } from '$app/stores';
    export let title = $page.data.siteName
    export let image = "/twitter-image.png"
    export let keywords = "manga, read manga, read manga online, request manga, manga reading website, populate manga, manga online, manga, manga details, manga chapters, read manga free, manga free, read free manga, read free manga online, manga reader, manga viewer, manga scans" + $page.data.siteName + $page.url.origin;
    export let description = 'Read the latest manga online for free at AnimeVariant, update fastest, most full, synthesized 24h free with high-quality images and be the first one to publish new chapters.';
</script>


<svelte:head>
	<title> {title}</title>
	<!-- Open Graph Meta Tags (for social media sharing) -->
	<meta property="og:title" content={title} />
	<meta
		property="og:description"
		content={description}
	/>
	<meta property="og:type" content="website" />
	<meta property="og:url" content={$page.url.origin} />
	<meta property="og:image" content={image} />
	<meta property="og:image:alt" content="{$page.data.siteName} Logo" />
	<meta property="og:site_name" content={title} />

	<!-- Twitter Meta Tags (for social media sharing) -->
	<meta name="twitter:card" content="summary_large_image" />
	<meta name="twitter:title" content={title} />
	<meta
		name="twitter:description"
		content={description}
	/>
	<meta name="twitter:image" content={image} />

	<!-- Google / Search Engine Tags -->
	<meta itemprop="name" content={title} />
	<meta
		itemprop="description"
		content={description}
	/>
	<meta itemprop="image" content={image} />

	<!-- Facebook Meta Tags (for social media sharing) -->
	<meta property="fb:app_id" content="AnimeVariant" />
	<meta property="fb:admins" content="AnimeVariant" />
	<meta property="fb:page_id" content="{$page.data.siteName}" />
	<meta property="fb:site_name" content="{$page.data.siteName}" />
	<meta property="article:publisher" content="{$page.data.siteName}" />
	<meta property="article:author" content="{$page.data.siteName}" />
	<meta property="article:section" content="{$page.data.siteName}" />
	<meta property="article:tag" content="{$page.data.siteName}" />
	<meta property="article:published_time" content="{$page.data.siteName}" />
	<meta property="article:modified_time" content="{$page.data.siteName}" />
	<meta property="article:expiration_time" content="{$page.data.siteName}" />
	<meta property="article:author:first_name" content="{$page.data.siteName}" />
	<meta property="article:author:last_name" content="{$page.data.siteName}" />
	<meta property="article:author:username" content="{$page.data.siteName}" />

	<!-- Schema.org Meta Tags (for SEO) -->
	<meta itemprop="headline" content={title} />
	<meta
		itemprop="description"
		content={description}
	/>
	<meta itemprop="image" content={image} />
	<!-- Keywords Meta Tag -->
	<meta
		name="keywords"
		content={keywords}
	/>
    <meta name="description" content={description} />
</svelte:head>
